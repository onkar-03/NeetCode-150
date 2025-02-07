#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Using Stack)
 * - We use a stack to track opening brackets as we traverse the string.
 * - If we encounter an opening bracket (`'('`, `'{'`, `'['`), we push it onto the stack.
 * - If we encounter a closing bracket (`')'`, `'}'`, `']'`), we check the top of the stack:
 *   - If it matches the corresponding opening bracket, we pop the stack.
 *   - Otherwise, the string is invalid, and we return `false`.
 * - At the end, the stack should be empty if all brackets are correctly balanced.
 * --------------------
 * T.C: O(n)
 * - We traverse the string once, and each operation (push/pop) takes O(1), leading to an overall complexity of O(n).
 * --------------------
 * S.C: O(n)
 * - In the worst case (only opening brackets), all characters are pushed onto the stack, leading to O(n) space complexity.
 */
class Solution
{
public:
  bool isValid(string s)
  {
    // Stack to store opening brackets
    stack<char> st;

    // Iterate through each character in the string
    for (char c : s)
    {
      // If it's an opening bracket, push it onto the stack
      if (c == '(' || c == '{' || c == '[')
      {
        st.push(c);
        continue; // Move to the next character
      }

      // If it's a closing bracket, check the top of the stack
      if (st.empty())
        return false; // If stack is empty, there's no matching opening bracket

      // Check if the top element in the stack matches the current closing bracket
      if (c == ')' && st.top() == '(')
      {
        st.pop(); // Valid pair found, remove the opening bracket
      }
      else if (c == '}' && st.top() == '{')
      {
        st.pop();
      }
      else if (c == ']' && st.top() == '[')
      {
        st.pop();
      }
      else
      {
        return false; // If it's an unmatched closing bracket, return false
      }
    }

    // Return true if stack is empty, meaning all brackets were balanced
    return st.empty();
  }
};

/*
 * Approach-2 (Using Stack with Direct Closing Bracket Matching)
 * - Instead of storing opening brackets, we push the expected closing brackets onto the stack.
 * - When encountering a closing bracket, we check if it matches the top of the stack:
 *   - If it matches, pop the stack.
 *   - If the stack is empty or does not match, return false.
 * - At the end, the stack should be empty for a valid string.
 * --------------------
 * T.C: O(n)
 * - We traverse the string once, and each operation (push/pop) takes O(1), leading to an overall complexity of O(n).
 * --------------------
 * S.C: O(n)
 * - In the worst case (only opening brackets), all characters are pushed onto the stack, leading to O(n) space complexity.
 */
class Solution
{
public:
  bool isValid(string s)
  {
    // Stack to store expected closing brackets
    stack<char> st;

    // Iterate through each character in the string
    for (char c : s)
    {
      // Push corresponding closing bracket for each opening bracket
      if (c == '(')
      {
        st.push(')');
      }
      else if (c == '{')
      {
        st.push('}');
      }
      else if (c == '[')
      {
        st.push(']');
      }
      // If stack is empty or top does not match the current closing bracket, return false
      else if (st.empty() || st.top() != c)
      {
        return false;
      }
      // Valid matching bracket found, pop the stack
      else
      {
        st.pop();
      }
    }

    // Return true only if stack is empty, meaning all brackets were matched
    return st.empty();
  }
};
