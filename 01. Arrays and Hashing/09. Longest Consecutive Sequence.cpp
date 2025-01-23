#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Brute Force using Hash Set
 * -------------------------------------------------------------
 * Time Complexity: O(N)
 * - We iterate over each element once and perform O(1) operations to check for the next consecutive element.
 * - The unordered_set allows O(1) average time complexity for the lookup.
 * ------------------------------------------------------------
 * Space Complexity: O(N)
 * - We store all the elements in the unordered_set, which takes O(N) space.
 */
class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    // Initialize the result variable to store the length of the longest streak
    int res = 0;

    // Use an unordered_set to store all the elements for O(1) lookups
    unordered_set<int> store(nums.begin(), nums.end());

    // Iterate through the entire list of numbers
    for (int num : nums)
    {
      int streak = 0; // Initialize the streak length for each number
      int curr = num; // Set the current number to start streak from

      // Continue checking for consecutive numbers while they exist in the set
      while (store.find(curr) != store.end())
      {
        streak++; // Increase streak length
        curr++;   // Move to the next consecutive number
      }

      // Update the result with the maximum streak length found
      res = max(res, streak);
    }

    // Return the length of the longest consecutive sequence found
    return res;
  }
};
