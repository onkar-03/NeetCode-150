#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-2: (Backtracking to Generate Valid Parentheses)
 * - We use a **backtracking approach** to generate all valid parentheses combinations.
 * - At each step, we can:
 *   - Add an **opening bracket `'('`** if `openN < n`.
 *   - Add a **closing bracket `')'`** if `closedN < openN` (to ensure validity).
 * - When `openN == closedN == n`, we have formed a valid string and add it to `res`.
 * - The function **backtracks** by removing the last added character after the recursive call.
 * --------------------
 * T.C: O(2^n)
 * - There are **exponential possibilities** since each position can be `'('` or `')'`.
 * - The recursion explores **all valid sequences** before pruning invalid cases.
 * --------------------
 * S.C: O(n)
 * - The recursion depth is at most `2n` (one call per bracket), leading to O(n) stack space.
 * - The `res` vector stores all valid sequences, but the main auxiliary space is O(n).
 * --------------------
 */
class Solution
{
public:
  void backtrack(int openN, int closedN, int n, vector<string> &res, string &stack)
  {
    // Base case: When a valid sequence is formed
    if (openN == closedN && openN == n)
    {
      res.push_back(stack);
      return;
    }

    // Add an opening bracket if we haven't used all 'n' yet
    if (openN < n)
    {
      stack += '(';
      backtrack(openN + 1, closedN, n, res, stack);
      stack.pop_back(); // Backtrack
    }

    // Add a closing bracket only if it won't make the sequence invalid
    if (closedN < openN)
    {
      stack += ')';
      backtrack(openN, closedN + 1, n, res, stack);
      stack.pop_back(); // Backtrack
    }
  }

  // Function to generate all valid parentheses combinations
  vector<string> generateParenthesis(int n)
  {
    vector<string> res;
    string stack;
    backtrack(0, 0, n, res, stack);
    return res;
  }
};
