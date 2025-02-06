#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Two Pointer Approach)
 * - We use two pointers (`i` at the start, `j` at the end) to compare characters while ignoring non-alphanumeric ones.
 * - Convert all characters to lowercase for uniform comparison.
 * - Skip non-alphanumeric characters using conditions.
 * - If at any point `s[i] != s[j]`, return false.
 * - Continue moving pointers inward until they meet.
 * --------------------
 * T.C: O(n)
 * - We traverse the string once with two pointers, filtering non-alphanumeric characters in O(1) checks.
 * - Each character is processed at most once, leading to a linear time complexity.
 * --------------------
 * S.C: O(1)
 * - We modify the string in place without extra space usage, making it constant space.
 */
class Solution
{
public:
  bool isPalindrome(string s)
  {
    int n = s.length(); // Get the length of the input string

    int i = 0;     // Left pointer
    int j = n - 1; // Right pointer

    // Convert all characters to lowercase for uniform comparison
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Iterate until both pointers meet
    while (i < j)
    {
      // Skip non-alphanumeric characters for `i`
      if (!((('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9'))))
      {
        i++;
      }

      // Skip non-alphanumeric characters for `j`
      if (!((('a' <= s[j] && s[j] <= 'z') || ('A' <= s[j] && s[j] <= 'Z') || ('0' <= s[j] && s[j] <= '9'))))
      {
        j--;
      }

      // Compare the filtered characters
      if (s[i] != s[j])
      {
        return false; // If characters mismatch, it's not a palindrome
      }

      // Move both pointers toward the center
      i++;
      j--;
    }

    return true; // If all character checks pass, it's a palindrome
  }
};

#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-2: (Two Pointer Approach with STL isalnum())
 * - We use two pointers (`i` at the start, `j` at the end) to compare characters while ignoring non-alphanumeric ones.
 * - Convert all characters to lowercase for uniform comparison.
 * - Skip non-alphanumeric characters using `isalnum()` from STL.
 * - If at any point `s[i] != s[j]`, return false.
 * - Continue moving pointers inward until they meet.
 * --------------------
 * T.C: O(n)
 * - We traverse the string once with two pointers, filtering non-alphanumeric characters in O(1) checks using `isalnum()`.
 * - Each character is processed at most once, leading to a linear time complexity.
 * --------------------
 * S.C: O(1)
 * - We modify the string in place without extra space usage, making it constant space.
 */
class Solution
{
public:
  bool isPalindrome(string s)
  {
    int n = s.length(); // Get the length of the input string

    int i = 0;     // Left pointer
    int j = n - 1; // Right pointer

    // Convert all characters to lowercase for uniform comparison
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Iterate until both pointers meet
    while (i < j)
    {
      // Move `i` forward if it's not an alphanumeric character
      while (i < j && !isalnum(s[i]))
        i++;

      // Move `j` backward if it's not an alphanumeric character
      while (i < j && !isalnum(s[j]))
        j--;

      // Compare the filtered characters
      if (s[i] != s[j])
      {
        return false; // If characters mismatch, it's not a palindrome
      }

      // Move both pointers toward the center
      i++;
      j--;
    }

    return true; // If all character checks pass, it's a palindrome
  }
};

/*
 * Approach-3: (Using Reverse Logic)
 * - We first filter the input string to keep only alphanumeric characters and convert them to lowercase.
 * - Then, we create a reversed version of the filtered string.
 * - Finally, we compare the original filtered string with the reversed one to check if it's a palindrome.
 * --------------------
 * T.C: O(n)
 * - We iterate through the string once to filter out non-alphanumeric characters and convert them to lowercase, which takes O(n).
 * - We reverse the filtered string, which also takes O(n).
 * - Therefore, the overall time complexity is O(n), where n is the length of the input string.
 * --------------------
 * S.C: O(n)
 * - We create a new string `filteredStr` to store the filtered characters, which takes O(n) space.
 * - We also create a new string `reversedStr` to store the reversed version of `filteredStr`, which also takes O(n) space.
 * - Therefore, the overall space complexity is O(n), where n is the length of the input string.
 */
class Solution
{
public:
  bool isPalindrome(string s)
  {
    // To store only alphanumeric characters in lowercase
    string filteredStr = "";

    // Step 1: Filter the input string to contain only alphanumeric characters and convert to lowercase
    for (char c : s)
    {
      if (isalnum(c))
      {
        // Add lowercase alphanumeric characters to filteredStr
        filteredStr += tolower(c);
      }
    }

    // Step 2: Compare the filtered string with its reverse

    // Copy the filtered string
    string reversedStr = filteredStr;

    // Reverse the string
    reverse(reversedStr.begin(), reversedStr.end());

    // If the original filtered string equals its reversed version, it's a palindrome
    return filteredStr == reversedStr;
  }
};
