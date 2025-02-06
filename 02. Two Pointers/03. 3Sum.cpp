#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force Simple Iteration
 * - arr[i] + arr[j] + arr[k] = 0 is the target
 * - Use three nested loops to check all possible triplets.
 * - If the sum of three elements is zero, store the triplet in a set to avoid duplicates.
 * - Sorting each triplet ensures uniqueness before insertion.
 * --------------------
 * T.C: O(n^3 * log(n))
 * - The three nested loops contribute O(n^3).
 * - Inserting into the set takes O(log(n)) per operation.
 * --------------------
 * S.C: O(2 * n)
 * - The set stores unique triplets, which can be O(2 * n) in the worst case, as we store the triplets in the set and also in the ans vector also 'n' is the number of triplets we get.
 */
class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    set<vector<int>> st; // To store unique triplets
    int n = nums.size(); // Get array size

    // Iterate over all possible triplets
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        for (int k = j + 1; k < n; k++)
        {
          // Check if the sum of triplet is zero
          if (nums[i] + nums[j] + nums[k] == 0)
          {
            vector<int> temp = {nums[i], nums[j], nums[k]};

            // Sort to maintain order
            sort(temp.begin(), temp.end());

            // Insert into the set to avoid duplicates
            st.insert(temp);
          }
        }
      }
    }

    // Convert set to vector
    vector<vector<int>> ans(st.begin(), st.end());

    // Return the vector
    return ans;
  }
};

/*
 * Approach-2: Using Hashing with Set
 * - Use an unordered set (hashset) to find the third element in O(1) time.
 * - Iterate through the array and fix one element.
 * - Use a hashset to track elements and find the required third element.
 * - Sort and store unique triplets using a set.
 * --------------------
 * T.C: O(n^2 * log(n))
 * - Outer loop runs O(n), and inner loop runs O(n), making it O(n^2).
 * - Inserting into the set takes O(log(n)) per operation.
 * --------------------
 * S.C: O(2 * n)
 * - The set stores unique triplets, which can be O(2 * n) in the worst case, as we store the triplets in the set and also in the ans vector also 'n' is the number of triplets we get.
 */
class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    set<vector<int>> st; // To store unique triplets
    int n = nums.size(); // Get array size

    // Iterate over the array and fix one element
    for (int i = 0; i < n; i++)
    {
      // Hashset for checking complements
      unordered_set<int> hashset;

      // Iterate for the second element
      for (int j = i + 1; j < n; j++)
      {
        int third = -(nums[i] + nums[j]); // Calculate required third element

        // Check if the third element is already in the hashset
        if (hashset.find(third) != hashset.end())
        {
          // If the element is already present, store the triplet in a vector
          vector<int> temp = {nums[i], nums[j], third};

          // Sort triplet to ensure uniqueness
          sort(temp.begin(), temp.end());

          // Insert into the set
          st.insert(temp);
        }

        // Store current element in the hashset
        hashset.insert(nums[j]);
      }
    }

    // Convert set to vector
    vector<vector<int>> ans(st.begin(), st.end());

    // Return the vector
    return ans;
  }
};

/*
 * Approach-3: Using 2 Pointers
 * - Sort the array first to efficiently use two pointers.
 * - Iterate through the array, and for each element, use two pointers to find pairs that sum to the negative of the current element.
 * - Skip duplicate elements to avoid repeating triplets.
 * - We eliminated HasSet usage and set data structure here which were used in previous approaches
 * --------------------
 * T.C: O(n^2)
 * - Sorting the array takes O(n log n).
 * - The two-pointer technique iterates through the array in O(n) for each element, giving O(n^2) in total.
 * --------------------
 * S.C: O(1)
 * - Only a few extra variables for pointers are used.
 */

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> ans;        // To store the resulting triplets
    int n = nums.size();            // Get array size
    sort(nums.begin(), nums.end()); // Sort the array to apply two-pointer technique

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
      // Skip duplicate elements to avoid repeating triplets
      if (i != 0 && nums[i] == nums[i - 1])
        continue;

      int j = i + 1; // Left pointer
      int k = n - 1; // Right pointer

      // Use two-pointer technique to find pairs
      while (j < k)
      {
        // Calculate sum of triplet
        int sum = nums[i] + nums[j] + nums[k];

        // Adjust pointers based on the sum
        // If sum is < 0 we need to increase the Sum $ as its a sorted array we need to move to bigger values i.e increase 'j'
        if (sum < 0)
        {
          j++; // Move left pointer to the right to increase sum
        }
        // If sum is > 0 we need to decrease the Sum & as its a sorted array we need to move to smaller values i.e decrease 'k'
        else if (sum > 0)
        {
          k--; // Move right pointer to the left to decrease sum
        }

        // Else we got a unique triplet thats already sorted so we store it in an array and push it in a set
        else
        {
          vector<int> temp = {nums[i], nums[j], nums[k]}; // Found a valid triplet
          ans.push_back(temp);

          // Move the left pointer right
          j++;

          // Move the right pointer left
          k--;

          // Skip duplicates after finding a valid triplet
          // Now after moving pointers ahead we need to make sure they are not the same in value as old ones hence we skip if thats the case
          while (j < k && nums[j] == nums[j - 1])
            j++;
          while (j < k && nums[k] == nums[k + 1])
            k--;
        }
      }
    }
    return ans; // Return the result
  }
};
