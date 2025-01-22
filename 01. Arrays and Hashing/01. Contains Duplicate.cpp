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

// Approach-3: Using Hash Set
// T.C : O(n) - We traverse the array once, and each set operation (insert and count) takes O(1) on average.
// S.C : O(n) - The unordered_set stores up to n unique elements in the worst case, resulting in space complexity of O(n).
class Solution
{
public:
  bool hasDuplicate(vector<int> &nums)
  {
    unordered_set<int> seen; // Create an unordered set to keep track of the elements we've seen so far

    // Traverse through each element in the array
    for (int num : nums)
    {
      // If the element is already in the set, we found a duplicate, return true
      if (seen.count(num))
      {
        return true;
      }
      // Otherwise, insert the current element into the set
      seen.insert(num);
    }

    // If no duplicates are found, return false
    return false;
  }
};

// Appraoch-4: Using Hsh Set Length
// T.C : O(n) - Creating the unordered_set from the array takes O(n), and getting the size of the set and array takes O(1) each.
// S.C : O(n) - The unordered_set stores up to n unique elements, so the space complexity is O(n).
class Solution
{
public:
  bool hasDuplicate(vector<int> &nums)
  {
    // Create an unordered set from the input array to automatically remove duplicates
    // Then compare the size of the set with the size of the original array
    // If the set size is smaller, it means there were duplicates in the array
    return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
  }
};

// Approach-5: Using Sorting
// T.C : O(n log n) - The sorting step takes O(n log n) time, and the loop to check for duplicates takes O(n) time. So the total time complexity is O(n log n).
// S.C : O(1) - The space complexity is constant (O(1)) because we are sorting in-place and not using any extra space (apart from a small amount of memory for variables).
class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    // Sort the array to bring any duplicate elements next to each other
    sort(nums.begin(), nums.end());

    // Traverse through the sorted array and check if adjacent elements are the same
    for (int i = 0; i < nums.size() - 1; i++)
    {
      if (nums[i] == nums[i + 1])
      {
        return true; // If a duplicate is found, return true
      }
    }

    // If no duplicates are found, return false
    return false;
  }
};