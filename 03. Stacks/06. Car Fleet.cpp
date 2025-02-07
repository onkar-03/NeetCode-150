#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Sorting + Stack Simulation using Vector)
 * - Each car's arrival time at the target is computed as `(target - position) / speed`.
 * - We **sort cars in decreasing order of position**, ensuring we process the nearest cars first.
 * - We use a **stack** to track distinct fleets:
 *   - If a car takes longer to reach than the last fleet, it forms a new fleet.
 *   - If a car reaches faster or at the same time as the last fleet, it merges.
 * --------------------
 * T.C: O(n log n)
 * - Sorting takes **O(n log n)**.
 * - The single pass through cars (with stack operations) takes **O(n)**.
 * - Overall, the dominant term is **O(n log n)** due to sorting.
 * --------------------
 * S.C: O(n)
 * - We use a **vector (stack)** to store the fleet times, leading to **O(n) worst-case space**.
 */
class Solution
{
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed)
  {
    vector<pair<int, int>> cars; // Store (position, speed) pairs
    for (int i = 0; i < position.size(); i++)
    {
      cars.push_back({position[i], speed[i]}); // Construct position-speed pairs
    }

    // Sort cars by position in descending order
    sort(cars.rbegin(), cars.rend());

    // Stack to store fleet times
    vector<double> stack;

    for (auto &car : cars)
    {
      // Calculate time to reach target
      double time = (double)(target - car.first) / car.second;

      // Push time into the stack
      stack.push_back(time);

      // If the current car reaches at or before the last fleet, merge it
      if (stack.size() >= 2 && stack.back() <= stack[stack.size() - 2])
      {
        stack.pop_back(); // Merge cars into the fleet
      }
    }

    return stack.size(); // Number of distinct fleets
  }
};

#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-2 (Sorting + Monotonic Stack)
 * - Each car's arrival time at the target is computed as `(target - position) / speed`.
 * - We **sort cars in decreasing order of position**, ensuring we process the nearest cars first.
 * - We use a **stack** to track distinct fleets:
 *   - If a car takes longer to reach than the last fleet, it forms a new fleet.
 *   - If a car reaches faster or at the same time as the last fleet, it merges.
 *   - We use `continue` to skip merging cars instead of explicitly popping them.
 * --------------------
 * T.C: O(n log n)
 * - Sorting takes **O(n log n)**.
 * - The single pass through cars (with stack operations) takes **O(n)**.
 * - Overall, the dominant term is **O(n log n)** due to sorting.
 * --------------------
 * S.C: O(n)
 * - In the worst case, all cars might be stored in the stack, leading to **O(n) space usage**.
 */
class Solution
{
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed)
  {
    vector<pair<int, int>> cars; // Store (position, speed) pairs
    int n = position.size();

    // Create position-speed pairs
    for (int i = 0; i < n; i++)
    {
      cars.push_back({position[i], speed[i]});
    }

    // Sort cars by position in descending order
    sort(cars.rbegin(), cars.rend());

    stack<double> st; // Stack to store fleet times

    for (auto &car : cars)
    {
      double time = (double)(target - car.first) / car.second; // Compute time to reach target

      // If the current car merges into an existing fleet, skip pushing it
      if (!st.empty() && time <= st.top())
      {
        // Merge, do not push
        continue;
      }

      st.push(time); // Push the new fleet time
    }

    return st.size(); // Number of distinct fleets
  }
};
