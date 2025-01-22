#include <bits/stdc++.h>
using namespace std;

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