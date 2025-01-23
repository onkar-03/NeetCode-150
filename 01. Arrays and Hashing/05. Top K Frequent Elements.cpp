#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Using Hash Map + Array & Sorting)
 * ---------------------------
 * Time Complexity: O(n * log(n))
 * - We iterate over each element in the input array 'nums' (n elements) and update the frequency in the hash map.
 * - Sorting the array of pairs (which contains the frequency and corresponding element) takes O(n * log(n)),
 *   where n is the number of unique elements in the input array.
 * ---------------------------
 * Space Complexity: O(n)
 * - We use an unordered_map to store the frequencies of the elements, which requires O(n) space where n is the number of unique elements.
 * - The result array also takes O(k) space, but since k ≤ n, the total space complexity is O(n).
 */

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    // Step 1: Count the frequency of each element in the input array
    unordered_map<int, int> count;
    for (int num : nums)
    {
      count[num]++; // Increment the frequency for each element
    }

    // Step 2: Store the frequency and element as pairs in a vector
    vector<pair<int, int>> arr;
    for (const auto &p : count)
    {
      // Pair (frequency, element)
      // We push the Frequency first as we want to sort based on frequency in while using sort
      arr.push_back({p.second, p.first});
    }

    // Step 3: Sort the vector of pairs in descending order of frequency
    // Sort in reverse (descending) order
    sort(arr.rbegin(), arr.rend());

    // Step 4: Select the top k elements with the highest frequency
    vector<int> res;
    for (int i = 0; i < k; ++i)
    {
      res.push_back(arr[i].second); // Add the element (second part of the pair) to the result
    }
    return res; // Return the result
  }
};

/*
 * Approach-2 (Using Hash Map + Min-Heap)
 * ---------------------------
 * Time Complexity: O(n log(k))
 * - In Worst Cazse we iterate over each element in the input array 'nums' (n elements) and update the frequency in the hash map (O(n)).
 * - We then push each element's frequency and value as a pair into the priority queue (min-heap). Each push operation takes O(log k) time.
 * - Since there are at most n elements in the map, and we perform k operations in the priority queue, the overall time complexity is O(n log(k)).
 * ---------------------------
 * Space Complexity: O(n + k)
 * - We use an unordered_map to store the frequencies of the elements, which requires O(n) space where n is the number of unique elements.
 * - The priority queue stores at most k elements, so it takes O(k) space.
 * - The result array takes O(k) space.
 */

class Solution
{
public:
  typedef pair<int, int> P; // Define a pair type P for better readability

  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    int n = nums.size(); // Get the size of the input array

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      mp[nums[i]]++; // Count the frequency of each element
    }

    priority_queue<P, vector<P>, greater<P>> pq; // Min-heap (priority queue)
    for (auto &it : mp)
    {
      int freq = it.second;     // Frequency of the current element
      int element = it.first;   // The element
      pq.push({freq, element}); // Insert into min-heap

      if (pq.size() > k)
      { // If heap size exceeds k, pop the element with the lowest frequency
        pq.pop();
      }
    }

    vector<int> result;
    while (!pq.empty())
    {
      int val = pq.top().second; // Get the element with the highest frequency
      result.push_back(val);     // Add to the result array
      pq.pop();                  // Remove the element from the heap
    }

    return result; // Return the result
  }
};

/*
 * Approach-3 (Using Hash Map + Bucket Sort)
 * ---------------------------
 * Time Complexity: O(n)
 * - In the worst case, we iterate over each element in the input array 'nums' (n elements) to count their frequencies in the hash map (O(n)).
 * - We then create a bucket array where each index represents a frequency, and we populate this bucket based on the frequency counts. This operation is also O(n) since we iterate through the unique elements in the frequency map.
 * - Finally, we gather the top K frequent elements by iterating through the bucket array.
 *   In the worst case, this can take O(n) time if k is large enough to require checking many buckets.
 * - Therefore, the overall time complexity is O(n).
 * ---------------------------
 * Space Complexity: O(n)
 * - We use an unordered_map to store the frequencies of the elements, which requires O(n) space where n is the number of unique elements in 'nums'.
 * - The bucket array itself takes O(n + k) space; however, since k ≤ n, we can simplify this to O(n).
 * - The result array takes O(k) space, but since k ≤ n, it does not change our overall space complexity.
 */

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    // Step 1: Get the size of the input array
    int n = nums.size();

    // Create a hash map to store the frequency of each element
    unordered_map<int, int> mp;

    // Iterate through each number in the input array
    for (int num : nums)
    {
      // Increment the frequency count for the current number
      mp[num]++;
    }

    // Step 2: Create a bucket array to group elements by frequency
    // Initialize a vector of vectors with size n + 1, where index represents frequency
    vector<vector<int>> bucket(n + 1);

    // Populate the bucket with elements based on their frequency
    for (const auto &it : mp)
    {
      int ele = it.first;          // Get the element (key) from the map
      int freq = it.second;        // Get the frequency (value) from the map
      bucket[freq].push_back(ele); // Place the element in the corresponding frequency bucket
    }

    // Step 3: Gather the top K frequent elements from the buckets
    vector<int> res; // Result vector to store the top K frequent elements

    // Loop through the bucket array from highest frequency to lowest
    for (int i = n; i > 0 && k > 0; i--)
    {
      // If there are no elements with this frequency, skip to next iteration
      if (bucket[i].size() == 0)
      {
        continue;
      }
      // While there are still elements in this frequency bucket and we need more results
      while (!bucket[i].empty() && k > 0)
      {
        // Add the last element from this bucket to the result vector
        res.push_back(bucket[i].back());
        // Remove that element from the bucket
        bucket[i].pop_back();
        // Decrement k as we have found one more frequent element
        k--;
      }
    }

    // Return the result vector containing the top K frequent elements
    return res;
  }
};
