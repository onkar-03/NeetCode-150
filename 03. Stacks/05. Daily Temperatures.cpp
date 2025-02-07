#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force)
 * - We iterate over each temperature and check for the first warmer day in the future.
 * - If found, we store the difference in indices; otherwise, we store 0.
 * --------------------
 * T.C: O(n²)
 * - For each element, we may traverse the entire remaining array in the worst case.
 * - This results in a nested loop leading to O(n²) complexity.
 * --------------------
 * S.C: O(n)
 * - We store the result array of size `n`, leading to O(n) additional space usage.
 */
class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size(); // Get the number of temperatures
    vector<int> res;             // Store the result

    for (int i = 0; i < n; i++)
    {                     // Iterate over each temperature
      bool found = false; // Flag to check if a warmer day is found
      for (int j = i + 1; j < n; j++)
      { // Check future days for a warmer temperature
        if (temperatures[j] > temperatures[i])
        {                       // If found
          res.push_back(j - i); // Store the number of days until the warmer temp
          found = true;         // Mark as found
          break;                // Stop searching for this day
        }
      }
      if (!found)
      {                   // If no warmer temperature was found
        res.push_back(0); // Push 0 into the result
      }
    }
    return res; // Return the final result array
  }
};

#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-2 (Monotonic Stack - Right to Left Traversal)
 * - We use a **monotonic decreasing stack** to store (temperature, index) pairs.
 * - We iterate from **right to left**, ensuring we efficiently find the next warmer day.
 * --------------------
 * T.C: O(n)
 * - Each element is pushed and popped from the stack at most once, leading to O(n) complexity.
 * --------------------
 * S.C: O(n)
 * - In the worst case, all temperatures might be stored in the stack, leading to O(n) space usage.
 */
class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size(); // Get the number of temperatures
    vector<int> res(n, 0);       // Initialize result array with 0s
    stack<pair<int, int>> st;    // Stack to store (temperature, index)

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && temperatures[i] >= st.top().first)
      {
        // Pop all smaller/equal temperatures
        st.pop();
      }

      // If a warmer day exists
      if (!st.empty())
      {
        // Calculate difference in indices
        res[i] = st.top().second - i;
      }

      // Push current temperature & index
      st.push({temperatures[i], i});
    }

    // Return the final result array
    return res;
  }
};
