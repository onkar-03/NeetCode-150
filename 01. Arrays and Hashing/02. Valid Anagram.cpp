#include <bits/stdc++.h>
using namespace std;

/*
 * Problem Statement:
 * ------------------
 * Given two strings 's' and 't', return true if 't' is an anagram of 's', and false otherwise.
 *
 * Explanation:
 * - An anagram is a word formed by rearranging the letters of another word,
 *   using all the original letters exactly once.
 * - For example:
 *   * "listen" and "silent" are anagrams.
 *   * "rat" and "car" are NOT anagrams.
 */

/*
 * Approach - 1: Sorting
 * ---------------------
 * Time Complexity: O(n log n)
 * - Sorting the first string 's' using .sort takes O(n log n).
 * - The sorting algorithm (like QuickSort, MergeSort, or IntroSort) has a time complexity of O(n log n),
 *   where 'n' is the length of the string.
 * - Sorting the second string 't' also takes O(n log n).
 * - Comparing the two sorted strings takes O(n).
 * - Total Time Complexity: O(n log n), dominated by the sorting steps.
 * ---------------------
 * Space Complexity: O(1)
 * - The sorting operation is in-place, meaning it does not require extra memory for a new array.
 * - Therefore, the additional space usage is constant: O(1).
 */

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    // If the lengths of the two strings are different, they cannot be
    // anagrams
    if (s.length() != t.length())
    {
      return false; // Return false immediately if lengths don't match
    }

    // Sort both strings alphabetically to make them comparable
    sort(s.begin(), s.end()); // Sort string 's'
    sort(t.begin(), t.end()); // Sort string 't'

    // After sorting, if the strings are identical, they are anagrams
    // Compare the sorted strings; if they are equal, return true
    return s == t;
  }
};

/*
 * Approach - 2: Hash Maps
 * -----------------------
 * Time Complexity: O(n)
 * - Iterating through the strings 's' and 't' takes O(n), where 'n' is the length of the strings.
 * - The comparison of two hash maps at the end takes O(k), where 'k' is the size of the hash map (at most 26 for lowercase English letters, so this is effectively O(1)).
 * - Total Time Complexity: O(n).
 * -----------------------
 * Space Complexity: O(k)
 * - Two unordered maps are used to store character frequencies.
 * - The maximum size of each map is limited to 26 (number of lowercase English letters),
 *   so the space complexity is effectively O(1).
 */

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    // Check if the lengths of the strings are different
    // If they are, it's impossible for them to be anagrams
    if (s.length() != t.length())
    {
      return false; // Return false immediately if lengths differ
    }

    // Create hash maps to store the frequency of each character in 's' and 't'
    unordered_map<char, int> countS; // Hash map for string 's'
    unordered_map<char, int> countT; // Hash map for string 't'

    // Iterate through each character in the strings
    for (int i = 0; i < s.length(); i++)
    {
      countS[s[i]]++; // Increment the frequency of character 's[i]' in countS
      countT[t[i]]++; // Increment the frequency of character 't[i]' in countT
    }

    // Compare the two hash maps
    // If they are equal, the strings are anagrams; otherwise, they are not
    return countS == countT;
  }
};
