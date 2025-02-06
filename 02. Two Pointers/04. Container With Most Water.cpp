#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force: Check all pairs of lines)
 * - We use two nested loops to check all pairs of lines in the array.
 * - For each pair of lines, we calculate the area formed between them by using the formula:
 *     - area = (j - i) * min(height[i], height[j]), where `i` and `j` are the indices of the two lines.
 * - We keep track of the maximum area encountered during the iteration.
 * --------------------
 * T.C: O(n^2)
 * - The outer loop runs `n` times, and for each iteration, the inner loop runs `n - i - 1` times, making the overall time complexity O(n^2).
 * --------------------
 * S.C: O(1)
 * - The solution uses a constant amount of extra space, so the space complexity is O(1).
 */

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int n = height.size();

    // Variable to store the maxArea
    int maxArea = INT_MIN;

    // Iterate through each pair of lines
    for (int i = 0; i < n; i++)
    {
      int area = 0;
      for (int j = i + 1; j < n; j++)
      {
        // Calculate the area for the pair of lines at indices i and j
        area = (j - i) * min(height[i], height[j]);

        // Update maxArea with the maximum area found
        maxArea = max(maxArea, area);
      }
    }

    // Return the maximum area
    return maxArea;
  }
};

/*
 * Approach-2 (Two-pointer approach for maximum area)
 * - We initialize two pointers, `i` and `j`, at the beginning and the end of the array respectively.
 * - We calculate the area between the lines at indices `i` and `j`, and update the result if we find a larger area.
 * - If `height[i] < height[j]`, we increment `i` to try and find a larger height at the left side.
 * - If `height[i] > height[j]`, we decrement `j` to try and find a larger height at the right side.
 * --------------------
 * T.C: O(n)
 * - We only traverse the array once with two pointers, so the time complexity is O(n).
 * --------------------
 * S.C: O(1)
 * - The solution uses constant extra space, so the space complexity is O(1).
 */

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int n = height.size();
    int res = INT_MIN;

    int i = 0;     // Left pointer
    int j = n - 1; // Right pointer

    while (i < j)
    {
      int area = (j - i) * min(height[i], height[j]);
      res = max(res, area);

      // Move the pointer for the smaller height
      // The logic is that we want to maximize the area of the container, which is determined by the shorter of the two heights (height[i] and height[j]) and the distance between the pointers.
      // Since the area is constrained by the shorter height, we move the pointer pointing to the smaller height in hope of finding a taller line that could maximize the area in future iterations.
      if (height[i] > height[j])
      {
        // Decrease right pointer if height[i] is greater, since moving the left pointer won't help us find a larger area
        j--;
      }
      else
      {
        // Increase left pointer if height[j] is greater or equal, since moving the right pointer won't help us find a larger area
        i++;
      }
    }
    return res; // Return the maximum area found
  }
};
