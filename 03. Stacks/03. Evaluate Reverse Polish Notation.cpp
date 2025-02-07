#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute FOrce Using In-Place Vector Modification
 * - Instead of using an explicit stack, we modify the `tokens` vector in place.
 * - We iterate through `tokens`, looking for operators (`+`, `-`, `*`, `/`).
 * - When an operator is found:
 *   - Convert the two preceding numbers to integers.
 *   - Perform the corresponding arithmetic operation.
 *   - Replace the three elements (`num1`, `num2`, `operator`) with the result.
 *   - Use `erase()` and `insert()` to modify the vector.
 * - Continue until only one element remains in `tokens`, which is the final result.
 * --------------------
 * T.C: O(n²)
 * - Each `erase()` operation takes **O(n)** (shifting elements).
 * - Since we process up to `n` elements, worst-case complexity is **O(n²)**.
 * --------------------
 * S.C: O(1)
 * - We modify `tokens` in place without using extra space, leading to **O(1) auxiliary space**.
 * --------------------
 */
class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    while (tokens.size() > 1)
    {
      for (int i = 0; i < tokens.size(); i++)
      {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
          // Convert the last two numbers before the operator to integers
          int a = stoi(tokens[i - 2]);
          int b = stoi(tokens[i - 1]);
          int result = 0;

          // Perform the operation
          if (tokens[i] == "+")
            result = a + b;
          else if (tokens[i] == "-")
            result = a - b;
          else if (tokens[i] == "*")
            result = a * b;
          else if (tokens[i] == "/")
            result = a / b;

          // Remove the two numbers and the operator, replacing them with the result
          tokens.erase(tokens.begin() + i - 2, tokens.begin() + i + 1);
          tokens.insert(tokens.begin() + i - 2, to_string(result));

          // Restart from the modified state
          break;
        }
      }
    }
    return stoi(tokens[0]); // The final result is the only remaining element
  }
};

/*
 * Approach-2: (Using Stack to Evaluate Reverse Polish Notation)
 * - We use a stack to evaluate the given Reverse Polish Notation (RPN) expression.
 * - Operands (numbers) are pushed onto the stack.
 * - When an operator (`+`, `-`, `*`, `/`) is encountered:
 *   - Pop the last two numbers from the stack.
 *   - Perform the operation with **correct operand order (`b op a`)**.
 *   - Push the result back onto the stack.
 * - At the end, the stack contains a single element, which is the final result.
 * --------------------
 * T.C: O(n)
 * - We iterate over `n` tokens, each operation (push/pop) takes O(1), so overall complexity is O(n).
 * --------------------
 * S.C: O(n)
 * - In the worst case, the stack holds `n/2` numbers and operators, leading to O(n) space usage.
 * --------------------
 */
class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> stack;
    for (const string &c : tokens)
    {
      if (c == "+")
      {
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();
        stack.push(b + a);
      }
      else if (c == "-")
      {
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();
        stack.push(b - a);
      }
      else if (c == "*")
      {
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();
        stack.push(b * a);
      }
      else if (c == "/")
      {
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();
        stack.push(b / a); // Correct order: b / a
      }
      else
      {
        stack.push(stoi(c)); // Convert string to int
      }
    }
    return stack.top(); // Return final result
  }
};
