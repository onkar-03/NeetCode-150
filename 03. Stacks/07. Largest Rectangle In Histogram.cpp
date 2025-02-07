#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-3: (Monotonic Stack)
 * - We use a **monotonic increasing stack** to store `(index, height)` pairs.
 * - The stack helps find the **nearest smaller height** to the left for each bar.
 * - Whenever we encounter a smaller height, we **pop** elements from the stack and calculate
 *   the area considering the popped height as the smallest in that rectangle.
 * --------------------
 * T.C: O(n)
 * - Each element is pushed onto the stack **once** and popped **once**, leading to **O(n)** complexity.
 * --------------------
 * S.C: O(n)
 * - The worst case occurs when the stack stores all elements, leading to **O(n) space usage**.
 */
class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    // Store the maximum area found
    int maxArea = 0;

    // Monotonic increasing stack storing (index, height) pairs
    stack<pair<int, int>> stack;

    // Iterate through each bar in the histogram
    for (int i = 0; i < heights.size(); i++)
    {
      // Start index for rectangle expansion
      int start = i;

      // Pop from stack if current height is smaller than the stack top's height
      while (!stack.empty() && stack.top().second > heights[i])
      {
        // Get the top element from the stack
        pair<int, int> top = stack.top();

        // Retrieve index and height of the previous taller bar
        int index = top.first;
        int height = top.second;

        // Calculate the maximum area with the popped height as the shortest
        maxArea = max(maxArea, height * (i - index));

        // Update start index for the next bar
        start = index;

        // Remove the processed element from the stack
        stack.pop();
      }

      // Push the current height with updated start index
      stack.push({start, heights[i]});
    }

    // Process remaining elements in the stack
    while (!stack.empty())
    {
      // Retrieve index and height of the remaining bar
      int index = stack.top().first;
      int height = stack.top().second;

      // Compute area considering the histogram extends till the last index
      maxArea = max(maxArea, height * (static_cast<int>(heights.size()) - index));

      // Remove the processed element from the stack
      stack.pop();
    }

    // Return the maximum rectangle area found
    return maxArea;
  }
};
