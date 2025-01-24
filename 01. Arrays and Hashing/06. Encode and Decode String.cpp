#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /*
   * Approach:
   * - We iterate through each string in the input vector.
   * - For each string, we first append its length (converted to string) followed by a '#' symbol and then the string itself.
   * - This forms an encoded string representing all the strings in the vector.
   * ----------------------------
   * Time Complexity (T.C.): O(n) where n is the total number of characters across all strings.
   * - We iterate through each string in the input vector and append its length and string to the result.
   * ----------------------------
   * Space Complexity (S.C.): O(n) where n is the total number of characters across all strings.
   * - We store the concatenated result in the string.
   */
  string encode(vector<string> &strs)
  {
    string res = ""; // Initialize the result string
    for (string s : strs)
    {                                         // Iterate through each string in the input vector
      res += to_string(s.length()) + '#' + s; // Append length, '#' and the string
    }
    return res; // Return the encoded string
  }

  /*
   * Approach:
   * - We iterate through the encoded string.
   * - For each substring between '#' symbols, we first extract the length of the string (before '#').
   * - Then, we extract the substring of that length (starting from after the '#').
   * - We repeat this process until we have extracted all strings from the encoded string.
   * ----------------------------
   * Time Complexity (T.C.): O(n) where n is the length of the encoded string.
   * - We traverse the string once and perform constant-time operations like substring extraction.
   * ----------------------------
   * Space Complexity (S.C.): O(n) where n is the total number of characters across all strings.
   * - We store the decoded strings in the result vector.
   */
  vector<string> decode(string s)
  {
    int n = s.length(); // Get the length of the encoded string
    vector<string> res; // Vector to store the decoded strings
    int i = 0;          // Pointer to traverse through the encoded string

    while (i < n)
    {            // Loop until the end of the string
      int j = i; // Set 'j' to the current index 'i'
      while (s[j] != '#')
      {      // Find the '#' that separates the length from the string
        j++; // Move 'j' to the next character
      }

      // Extract the length (substring from i to j)
      int len = stoi(s.substr(i, j - i)); // Convert the length substring to an integer

      // Extract the string of length 'len'
      string str = ""; // Initialize an empty string to hold the decoded string
      for (int k = j + 1; k < j + 1 + len; k++)
      {              // Loop through the characters of the string
        str += s[k]; // Append each character to the result string
      }

      res.push_back(str); // Add the decoded string to the result vector

      // Move the index 'i' to the next part of the string after the current string and its length
      i = j + 1 + len; // Skip past the current string and its length information
    }

    return res; // Return the decoded strings
  }
};
