#include <bits/stdc++.h>
using namespace std;

/*
 * Approach - 1: Brute Force
 * ----------------------------
 * Time Complexity: O(n^2)
 * - The outer loop runs 'n' times, and for each iteration, the inner loop runs (n-1) times in the worst case.
 * - This results in O(n^2) operations due to nested loops.
 * ----------------------------
 * Space Complexity: O(1)
 * - No extra space is used other than variables for indices and the result.
 * ----------------------------
 */
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int n = nums.size(); // Get the size of the input array 'nums'

    // Outer loop iterates over each element of the array
    for (int i = 0; i < n; i++)
    {
      // Inner loop starts from the next element to avoid checking the same pair again
      for (int j = i + 1; j < n; j++)
      {
        // Check if the sum of the current pair equals the target
        if (nums[i] + nums[j] == target)
        {
          // If found, return the indices of the two numbers
          return {i, j};
        }
      }
    }

    // If no such pair is found
    // Note: This return is not strictly required as the problem guarantees one solution
    return {};
  }
};

// Approach-2: Hashing using Unordered Map
// T.C : O(n) - We traverse the array only once, and for each element, we check if the complement exists in the map, which takes constant time (O(1)) on average.
// S.C : O(n) - We use an unordered_map to store elements and their indices. In the worst case, the map will contain 'n' elements, where 'n' is the size of the input array.
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int n = nums.size(); // Get the size of the input array

    unordered_map<int, int> mp; // Create an unordered map (hash map) to store the element values and their indices

    // Traverse through the array
    for (int i = 0; i < n; i++)
    {
      int remaining = target - nums[i]; // Calculate the remaining value needed to reach the target

      // If the remaining value is found in the map, we found the two indices
      if (mp.find(remaining) != mp.end())
      {
        return {mp[remaining], i}; // Return the pair of indices that add up to the target
      }

      // Otherwise, store the current element's value and its index in the map
      mp[nums[i]] = i;
    }

    // If no such pair is found, return an empty vector (edge case handling)
    return {};
  }
};

/*
 * Approach - 2: Hashing using Unordered Map One Pass
 * ----------------------------------------
 * Time Complexity (T.C): O(n)
 * - We traverse the array once (O(n)).
 * - For each element, checking if its complement exists in the map takes constant time on average (O(1)).
 * - Total Time Complexity: O(n).
 * ----------------------------------------
 * Space Complexity (S.C): O(n)
 * - We use an unordered map to store up to 'n' elements in the worst case, where 'n' is the size of the input array.
 * - Total Space Complexity: O(n).
 */

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int n = nums.size(); // Get the size of the input array

    unordered_map<int, int> mp; // Create an unordered map to store element values and their indices

    // Traverse through the array
    for (int i = 0; i < n; i++)
    {
      int remaining = target - nums[i]; // Calculate the remaining value needed to reach the target

      // Check if the complement (remaining value) exists in the map
      if (mp.find(remaining) != mp.end())
      {
        // If found, return the indices of the current element and its complement
        return {mp[remaining], i};
      }

      // Otherwise, store the current element's value and its index in the map
      mp[nums[i]] = i;
    }

    // If no such pair is found, return an empty vector (edge case handling)
    return {};
  }
};
