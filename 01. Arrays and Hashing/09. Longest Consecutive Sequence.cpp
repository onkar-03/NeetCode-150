#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Brute Force using Hash Set
 * ----------------------------
 * Time Complexity: O(N)
 * - We iterate over each element once and perform O(1) operations to check for the next consecutive element.
 * - The unordered_set allows O(1) average time complexity for the lookup.
 * ----------------------------
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

/*
 * Approach- 2: Using Hash Set & Left Neighbour Logic
 * ----------------------------
 * 1. Store all elements in an unordered_set to allow O(1) lookups.
 * 2. Iterate through each element in the set:
 *    - Check if the current number is the start of a potential sequence (i.e., `num - 1` is not in the set)
 *    - If it is, calculate the length of the sequence by checking consecutive numbers (`num + 1`, `num + 2`, ...).
 *    - Update the longest sequence length found so far.
 * 3. Return the maximum sequence length after checking all numbers.
 * ----------------------------
 * Time Complexity (T.C): O(n)
 * - Each element is visited at most twice: once for the initial iteration and once for checking consecutive elements.
 * - The unordered_set allows O(1) lookups.
 * ----------------------------
 * Space Complexity (S.C): O(n)
 * - The unordered_set stores all unique elements of the input array.
 */

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    // Step 1: Store all elements in an unordered_set for O(1) lookups
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0; // Initialize the variable to store the longest sequence length

    // Step 2: Iterate through each number in the set
    for (int num : numSet)
    {
      // Check if the current number is the start of a sequence
      // (i.e., `num - 1` is not in the set, so `num` is the smallest in its sequence)
      if (numSet.find(num - 1) == numSet.end())
      {
        int length = 1; // Initialize the length of the current sequence

        // Step 3: Find consecutive numbers in the sequence
        while (numSet.find(num + length) != numSet.end())
        {
          length++; // Increase the sequence length as we find consecutive numbers
        }

        // Step 4: Update the longest sequence length
        longest = max(longest, length);
      }
    }

    // Step 5: Return the maximum sequence length found
    return longest;
  }
};

/*
 * Approach-3: Using Sorting
 * ----------------------------
 * 1. If the input array is empty, return 0 immediately.
 * 2. Sort the input array, which groups all identical elements together and arranges numbers in ascending order.
 * 3. Use a single loop to iterate through the array:
 *    - Keep track of the current number (`curr`) and the length of the current sequence (`streak`).
 *    - If the current number in the array is not equal to `curr`, reset the streak.
 *    - Skip duplicate elements in the array.
 *    - Increment the streak as long as consecutive elements are found and update the result (`res`) with the maximum streak length.
 * 4. Return the longest streak found.
 * ----------------------------
 * Time Complexity (T.C): O(n log n)
 * - Sorting the array takes O(n log n), where n is the size of the array.
 * - The single traversal of the array to calculate the longest streak takes O(n).
 * - Overall T.C: O(n log n).
 * ----------------------------
 * Space Complexity (S.C): O(1)
 * - Sorting is done in place, and no additional data structures are used, apart from a few integer variables.
 */

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    // Step 1: Handle the edge case where the input array is empty
    if (nums.empty())
      return 0;

    // Step 2: Sort the input array to group duplicates and arrange in ascending order
    sort(nums.begin(), nums.end());

    // Initialize variables for tracking the longest sequence
    int res = 0;        // Stores the result (maximum sequence length)
    int curr = nums[0]; // Tracks the current number being evaluated
    int streak = 0;     // Length of the current consecutive sequence
    int i = 0;          // Index for iterating through the array

    // Step 3: Traverse the sorted array to find the longest consecutive sequence
    while (i < nums.size())
    {
      // If the current number is different from the last processed number, reset the streak
      if (curr != nums[i])
      {
        curr = nums[i]; // Update the current number
        streak = 0;     // Reset the streak length
      }

      // Skip over duplicates in the array
      while (i < nums.size() && nums[i] == curr)
      {
        i++; // Move to the next unique number
      }

      // Increment the streak and move to the next consecutive number
      streak++;
      curr++; // Increment `curr` to look for the next consecutive number

      // Update the result with the maximum streak found so far
      res = max(res, streak);
    }

    // Step 4: Return the maximum consecutive sequence length
    return res;
  }
};