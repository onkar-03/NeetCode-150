#include <bits/stdc++.h>
using namespace std;

// Appraoch-1: Brute Force
// T.C : O(n^2) - We use two nested loops to compare each element with every other element, resulting in a quadratic time complexity.
// S.C : O(1) - The space complexity is constant since we are not using any extra data structures.
class Solution
{
public:
  bool hasDuplicate(vector<int> &nums)
  {
    // Traverse through each element in the array
    for (int i = 0; i < nums.size(); i++)
    {
      // Compare the current element with every subsequent element in the array
      for (int j = i + 1; j < nums.size(); j++)
      {
        // If a duplicate is found, return true
        if (nums[i] == nums[j])
        {
          return true;
        }
      }
    }
    // If no duplicates are found, return false
    return false;
  }
};

// Approach : Using Hash Map
// T.C : O(n) - We iterate through the array once, and each map operation (find and insert) takes O(1) on average
// S.C : O(n) - The unordered_map stores up to n elements in the worst case.
class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the input array

    unordered_map<int, int> mp; // Create an unordered map (hash map) to store the frequency of each element

    // Traverse through the array
    for (int i = 0; i < n; i++)
    {
      // Check if the current element already exists in the map
      if (mp.find(nums[i]) != mp.end())
      {
        // If it exists, it means we have found a duplicate, so return true
        return true;
      }
      // If the element is not found, store it in the map with a frequency count of 1
      mp[nums[i]] += 1;
    }

    // If no duplicates are found after checking all elements, return false
    return false;
  }
};