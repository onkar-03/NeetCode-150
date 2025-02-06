#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force)
 * - We iterate through each element in the array, and for each element, we check every subsequent element.
 * - We check if the sum of the two elements equals the target.
 * - If the sum matches, we return the 1-based indices of the two elements.
 * --------------------
 * T.C: O(n^2)
 * - For each element, we check every other element in the array. This results in two nested loops.
 * - Therefore, the time complexity is O(n^2), where n is the number of elements in the array.
 * --------------------
 * S.C: O(1)
 * - We don't use any extra space (other than a few variables), so the space complexity is constant.
 */

class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int n = numbers.size();

    // We don't need an extra vector for storing the result, just return directly as we are told that there is exactly one solution
    for (int i = 0; i < n; i++)
    {
      int j = i + 1;
      while (j < n)
      {
        if (numbers[i] + numbers[j] == target)
        {
          // Return 1-based indices directly
          return {i + 1, j + 1};
        }
        j++;
      }
    }

    // This line will never be reached because there is exactly one solution
    return {};
  }
};

/*
 * Approach-2 (Two-pointer approach for sorted array)
 * - We use two pointers:
 *   - One pointer at the beginning (`i = 0`) and another at the end (`j =
 * n-1`).
 *   - We calculate the sum of the two elements at these pointers:
 *     - If the sum equals the target, we return their 1-based indices.
 *     - If the sum is less than the target, we move the left pointer to the
 * right.
 *     - If the sum is greater than the target, we move the right pointer to the
 * left.
 * --------------------
 * T.C: O(n)
 * - The two pointers move towards each other, each pointer only moving once.
 * - Therefore, the time complexity is O(n), where n is the number of elements
 * in the array.
 * --------------------
 * S.C: O(1)
 * - We only use a constant amount of extra space (for the two pointers and the
 * result).
 * - Therefore, the space complexity is O(1).
 */

class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    // Size of the Vector
    int n = numbers.size();

    int i = 0;     // Left pointer
    int j = n - 1; // Right pointer

    while (i < j)
    {
      // Check if the sum of the two pointers equals the target
      if (numbers[i] + numbers[j] == target)
      {
        return {i + 1, j + 1}; // Return 1-based indices
      }
      else if (numbers[i] + numbers[j] > target)
      {
        j--; // Decrease the right pointer if the sum is too large
      }
      else
      {
        i++; // Increase the left pointer if the sum is too small
      }
    }

    // This line will never be reached because there is exactly one solution
    return {};
  }
};
