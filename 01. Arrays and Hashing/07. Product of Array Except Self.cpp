#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: (Using Nested Loops)
 * ---------------------------
 * Time Complexity: O(n^2)
 * - In the worst case, we iterate over each element in the input array 'nums' (n elements).
 * - For each element, we perform another iteration over all elements to calculate the product
 *   of all other elements (excluding the current one). This results in a nested loop structure.
 * - Therefore, the overall time complexity is O(n^2) due to the double iteration.
 * ---------------------------
 * Space Complexity: O(1)
 * - We use only the result array to store final products, which requires O(n) space.
 * - No additional arrays are used, so the space complexity is considered O(1) in terms of auxiliary space.
 */
#include <vector>

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    // Step 1: Get the size of the input array
    int n = nums.size();

    // Step 2: Create a result array to store the products
    vector<int> res(n);

    // Step 3: Calculate the product for each index
    for (int i = 0; i < n; i++)
    {
      int prod = 1; // Initialize product for the current index
      // Inner loop to calculate product of all elements except nums[i]
      for (int j = 0; j < n; j++)
      {
        if (i != j)
        {                  // Skip the current index
          prod *= nums[j]; // Multiply with other elements
        }
      }
      res[i] = prod; // Store the calculated product in result array
    }
    return res; // Return the result array
  }
};

/*
 * Approach-2: (Using Product Calculation, Divison with 0 Handling)
 * ---------------------------
 * Time Complexity: O(n)
 * - We iterate through the input array 'nums' twice: once to calculate the product of all non-zero
 *   elements and count the number of zeros (O(n)).
 * - In the second pass, we populate the result array based on the number of zeros and the product
 *   calculated in the first pass (O(n)).
 * - Therefore, the overall time complexity is O(n).
 * ---------------------------
 * Space Complexity: O(1)
 * - We use only the result array to store final products, which requires O(n) space.
 * - No additional arrays are used, so the space complexity is considered O(1) in terms of auxiliary space.
 */

#include <vector>

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    long long prod = 1; // Variable to store the product of all non-zero elements
    int zero = 0;       // Counter to track the number of zeros in the array
    vector<int> ans;    // Vector to store the result

    // Step 1: Calculate the product of all non-zero elements and count zeros
    for (auto num : nums)
    {
      if (num != 0)
      {
        prod = prod * num; // Multiply non-zero elements
      }
      else
      {
        zero++; // Increment zero count if element is zero
      }
    }

    // Step 2: Populate the result array based on the number of zeros
    for (auto num : nums)
    {
      if (zero > 1)
      {
        // If more than one zero exists, all products will be 0
        ans.push_back(0);
      }
      else if (num != 0)
      {
        if (zero > 0)
        {
          // If exactly one zero exists, all non-zero elements will contribute 0
          ans.push_back(0);
        }
        else
        {
          // No zeros: Calculate the product except self by dividing `prod` by the current element
          ans.push_back(prod / num);
        }
      }
      else
      {
        // If the current element is 0, it will contribute the product of all other elements
        ans.push_back(prod);
      }
    }
    return ans; // Return the final result
  }
};

/*
 * Approach-3: (Using Prefix and Suffix Products)
 * ---------------------------
 * Time Complexity: O(n)
 * - We iterate through the input array 'nums' three times: once to calculate the prefix products,
 *   once to calculate the suffix products, and once to compute the final result.
 * - Each of these operations runs in O(n), leading to an overall time complexity of O(n).
 * ---------------------------
 * Space Complexity: O(n)
 * - We use two additional arrays, 'pref' and 'suff', to store the prefix and suffix products, each requiring O(n) space.
 * - Therefore, the total space complexity is O(n).
 */

#include <vector>

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the input array
    vector<int> res(n);  // Result array to store final products
    vector<int> pref(n); // Array to store prefix products
    vector<int> suff(n); // Array to store suffix products

    // Step 1: Calculate prefix products
    pref[0] = 1; // The product of elements before the first element is 1
    for (int i = 1; i < n; i++)
    {
      pref[i] = nums[i - 1] * pref[i - 1]; // Calculate prefix product up to index i
    }

    // Step 2: Calculate suffix products
    suff[n - 1] = 1; // The product of elements after the last element is 1
    for (int i = n - 2; i >= 0; i--)
    {
      suff[i] = nums[i + 1] * suff[i + 1]; // Calculate suffix product from index i to end
    }

    // Step 3: Calculate result by multiplying prefix and suffix products
    for (int i = 0; i < n; i++)
    {
      res[i] = pref[i] * suff[i]; // Final product for each index is prefix[i] * suffix[i]
    }

    return res; // Return the final result array
  }
};

/*
 * Approach (Optimal Prefix & Postfix Method)
 * ---------------------------
 * Time Complexity: O(n)
 * - We iterate through the input array 'nums' twice: once to calculate the prefix products
 *   directly into the result array, and once to calculate the postfix products while updating
 *   the result array.
 * - Therefore, the overall time complexity is O(n).
 * ---------------------------
 * Space Complexity: O(1)
 * - We use only the result array to store final products, which requires O(n) space.
 * - No additional arrays are used, so the space complexity is considered O(1) in terms of
 *   auxiliary space.
 */

#include <vector>

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();   // Get the size of the input array
    vector<int> res(n, 1); // Result array initialized to 1

    // Step 1: Calculate prefix products directly in res
    for (int i = 1; i < n; i++)
    {
      res[i] = res[i - 1] * nums[i - 1]; // Calculate prefix product up to index i
    }

    // Step 2: Calculate postfix products and multiply with prefix in res
    // Variable to store postfix product
    int postfix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
      res[i] *= postfix;  // Multiply with current postfix product
      postfix *= nums[i]; // Update postfix product for next iteration
    }

    return res; // Return the final result array
  }
};