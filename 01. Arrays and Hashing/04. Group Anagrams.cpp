#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Using Sorting and Mapping)
 * ---------------------------
 * Time Complexity: O(n * k * log(k))
 * - We iterate over each string in the input (n strings). For each string, we sort it, which takes O(k * log(k)),
 * where k is the maximum length of a string in the input.
 *
 * Space Complexity: O(n * k)
 * - We store the strings in an unordered map, where the total number of characters stored is O(n * k),
 * and the strings themselves take O(k) space.
 */

class Solution
{
public:
  // Declare a function that takes a vector of strings as input and returns a vector of vector of strings
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {

    // Create an unordered map to store sorted strings as keys and their corresponding anagrams as values
    unordered_map<string, vector<string>> mp;

    // Traverse through each string in the input vector
    for (auto str : strs)
    {

      // Make a copy of the current string to sort it
      string temp = str;

      // Sort the characters of the string
      sort(temp.begin(), temp.end());

      // Add the original string to the vector of anagrams for the sorted string
      mp[temp].push_back(str);
    }

    // Create a vector to hold the result, which is a vector of anagram groups
    vector<vector<string>> result;

    // Traverse through the unordered map and add each vector of anagrams to the result vector
    for (auto it : mp)
    {
      result.push_back(it.second);
    }

    // Return the result vector containing the grouped anagrams
    return result;
  }
};

/*
 * Approach-2 (Using Frequency Array and Mapping)
 * ---------------------------
 * Time Complexity: O(n * k)
 * - We iterate over each string in the input (n strings). For each string, we count the frequency of characters, which takes O(k),
 * where k is the maximum length of a string in the input.
 *
 * Space Complexity: O(n * k)
 * - We store the strings in an unordered map, where the total number of characters stored is O(n * k), and the strings themselves take O(k) space.
 */
class Solution
{
public:
  // Helper function to generate a canonical form of the string
  string generate(string &s)
  {
    int count[26] = {0}; // Array to store frequency of each character (26 letters in the alphabet)

    // Traverse the string to count the frequency of each character
    for (char &ch : s)
    {
      count[ch - 'a']++; // Increment the frequency for each character
    }

    string new_s; // String to hold the canonical form of the input string

    // Reconstruct the string using the frequencies of each character
    for (int i = 0; i < 26; i++)
    {
      { // Only append characters that appear in the original string
        if (count[i] > 0)
          // Add the character `count[i]` times to the result string
          new_s += string(count[i], i + 'a');
      }
    }

    return new_s; // Return the generated canonical form of the string
  }

  // Main function to group anagrams
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> mp; // Map to store the canonical form as the key and list of anagrams as the value

    // Traverse through the input strings
    for (string &s : strs)
    {
      string new_s = generate(s); // Generate the canonical form of the string

      mp[new_s].push_back(s); // Group the string by its canonical form
    }

    vector<vector<string>> result; // Vector to hold the final grouped anagrams

    // Add the grouped anagrams from the map to the result vector
    for (auto &it : mp)
    {
      result.push_back(std::move(it.second)); // Use move to efficiently transfer ownership of the vector
    }

    return result; // Return the grouped anagrams
  }
};