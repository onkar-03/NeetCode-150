#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Using Precomputed LeftMax and RightMax Arrays)
 * - We precompute two arrays:
 *     leftMax[i]:  the maximum height from index 0 to i.
 *     rightMax[i]: the maximum height from index i to n-1.
 *
 * - The water trapped at index i is:
 *       water[i] = min(leftMax[i], rightMax[i]) - height[i]
 * - We iterate over the array once to compute `leftMax`, once for `rightMax`, and once to calculate the total water.
 * --------------------
 * T.C: O(n)
 * - We iterate through the array 3 times (leftMax, rightMax, and water sum), making it O(n).
 * --------------------
 * S.C: O(n)
 * - We use two auxiliary arrays (`leftMax` and `rightMax`), each of size `n`, leading to O(n) space complexity.
 */
class Solution
{
public:
  // Function to compute the maximum height to the left of each index
  vector<int> getLeftMax(vector<int> &height, int n)
  {
    // Stores maximum height encountered from the left
    vector<int> leftMax(n);

    // The leftmost element is its own max
    leftMax[0] = height[0];

    // Iterate through the array and compute the left max at each index
    for (int i = 1; i < n; i++)
    {
      leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Return the computed left max array
    return leftMax;
  }

  // Function to compute the maximum height to the right of each index
  vector<int> getRightMax(vector<int> &height, int n)
  {
    // Stores maximum height encountered from the right
    vector<int> rightMax(n);

    // The rightmost element is its own max
    rightMax[n - 1] = height[n - 1];

    // Iterate backwards to compute the right max at each index
    for (int i = n - 2; i >= 0; i--)
    {
      rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // Return the computed right max array
    return rightMax;
  }

  // Function to calculate the total trapped water
  int trap(vector<int> &height)
  {
    // Get the size of the height array
    int n = height.size();

    // If there's only one or zero elements, no water can be trapped
    if (n == 1 || n == 0)
      return 0;

    // Compute the left and right max arrays
    vector<int> leftMax = getLeftMax(height, n);
    vector<int> rightMax = getRightMax(height, n);

    // Stores the total trapped water
    int sum = 0;

    // Calculate trapped water at each index
    for (int i = 0; i < n; i++)
    {
      sum += min(leftMax[i], rightMax[i]) - height[i];

      /*
       * - Since leftMax[i] is computed by considering height[i] itself (and similarly for rightMax[i]),
       *   we always have leftMax[i] >= height[i] and rightMax[i] >= height[i]. Thus:
       *       min(leftMax[i], rightMax[i]) >= height[i]
       *   This guarantees that (min(leftMax[i], rightMax[i]) - height[i]) is never negative.
       *
       * Example:
       *   For height = [3, 0, 3]:
       *     leftMax  = [3, 3, 3]
       *     rightMax = [3, 3, 3]
       *     At index 1: water = min(3, 3) - 0 = 3.
       *     (The subtraction never produces a negative value.)
       */
    }

    // Return the total trapped water
    return sum;
  }
};

/*
 * Approach-2 (Using Two Pointers)
 * - We maintain two pointers (`l` and `r`) starting at the leftmost and rightmost indices.
 * - We track `maxLeft` and `maxRight`, which store the highest boundaries encountered so far.
 * - At each step:
 *     If maxLeft < maxRight, then the water level at the left pointer is determined by maxLeft.
 *     We move the left pointer to the right and add (maxLeft - height[l]) to the sum.
 *     Otherwise, the water level at the right pointer is determined by maxRight.
 *     We move the right pointer to the left and add (maxRight - height[r]) to the sum.
 *  * - The trapped water at any index is determined by the formula:
 *   `water[i] = min(maxLeft, maxRight) - height[i]`
 * --------------------
 * T.C: O(n)
 * - We traverse the array only once with two pointers, leading to O(n) time complexity.
 * --------------------
 * S.C: O(1)
 * - No extra space is used apart from a few integer variables, making space complexity O(1).
 */
class Solution
{
public:
  int trap(vector<int> &height)
  {
    // Get the size of the height array
    int n = height.size();

    // If there are less than 3 elements, no water can be trapped
    if (n <= 2)
      return 0;

    // Stores the total trapped water
    int sum = 0;

    // Left and right pointers
    int l = 0, r = n - 1;

    // Maximum heights encountered from left and right
    int maxLeft = height[l], maxRight = height[r];

    // Process the height array using two pointers
    while (l < r)
    {
      // If left boundary is smaller, process the left side
      if (maxLeft < maxRight)
      {
        l++;                               // Move the left pointer forward
        maxLeft = max(maxLeft, height[l]); // Update maxLeft
        sum += maxLeft - height[l];        // Calculate trapped water
      }
      // Otherwise, process the right side
      else
      {
        r--;                                 // Move the right pointer backward
        maxRight = max(maxRight, height[r]); // Update maxRight
        sum += maxRight - height[r];         // Calculate trapped water
      }
    }

    // Return the total trapped water
    return sum;
  }
};

/*
 * WHY NO NEGETIVE VALUE CHECK ??
 * - Since maxLeft and maxRight are updated to be at least as high as the current bar, the expression
 *   (maxLeft - height[l]) or (maxRight - height[r]) is never negative.
 *
 * Example:
 *   For height = [0, 2, 0, 3]:
 *     Initialization:
 *         l = 0, r = 3, maxLeft = 0, maxRight = 3.
 *     Step 1:
 *         Since maxLeft (0) < maxRight (3), move l to 1.
 *         Update maxLeft = max(0, 2) = 2.
 *         Water at index 1 = 2 - 2 = 0.
 *     Step 2:
 *         maxLeft (2) < maxRight (3), move l to 2.
 *         maxLeft remains 2.
 *         Water at index 2 = 2 - 0 = 2.
 *     Total trapped water = 0 + 2 = 2.
 */
