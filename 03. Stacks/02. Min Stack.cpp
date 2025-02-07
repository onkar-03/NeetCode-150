#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Using Temporary Stack for `getMin()`)
 * - We use a single stack (`stk`) to store values and compute the minimum dynamically.
 * - The `getMin()` function recalculates the minimum every time it is called, making it inefficient.
 * - To find the minimum:
 *   - A temporary stack (`tmp`) is used to store elements while scanning for the minimum.
 *   - The stack is fully emptied, and the minimum value (`mini`) is updated during the process.
 *   - After finding `mini`, all elements are pushed back from `tmp` to restore the original stack order.
 *
 * Dry Run Example:
 * Suppose we push `[5, 3, 7, 2, 6]` into the MinStack.
 *
 * | Action       | Stack (`stk`) |
 * |-------------|---------------|
 * | `push(5)`   | `[5]`         |
 * | `push(3)`   | `[5,3]`       |
 * | `push(7)`   | `[5,3,7]`     |
 * | `push(2)`   | `[5,3,7,2]`   |
 * | `push(6)`   | `[5,3,7,2,6]` |
 *
 * Calling `getMin()`:
 * - `mini = stk.top() = 6`
 * - Iterating through `stk`, updating `mini = 2`
 * - Elements are stored in `tmp` and restored back.
 * - **Final output: `getMin()` returns `2`**.
 *
 * --------------------
 * T.C: O(2 * n) for `getMin()`, O(1) for other operations
 * - push()   → **O(1)**  (Push element to `stk`)
 * - pop()    → **O(1)**  (Remove top element)
 * - top()    → **O(1)**  (Access top element)
 * - getMin() → **O(n)**  (Scan entire stack + restore elements)
 *
 * Overall, for **n operations**, total time complexity = **O(n²) worst case**.
 *
 * --------------------
 * S.C: O(2 * n) → **O(n)**
 * - Uses an extra temporary stack (`tmp`), which can store up to `n` elements.
 * - Since `stk` and `tmp` exist simultaneously during `getMin()`, total space = **O(2n) → O(n)**.
 */
class MinStack
{
public:
  // Stack to store all elements
  stack<int> stk;

  // Constructor initializes an empty stack
  MinStack() {}

  // Pushes a value onto the stack
  void push(int val)
  {
    stk.push(val);
  }

  // Removes the top element from the stack
  void pop()
  {
    stk.pop();
  }

  // Returns the top element without removing it
  int top()
  {
    return stk.top();
  }

  // Returns the minimum element by iterating through the stack
  int getMin()
  {
    // Temporary stack to store elements while finding min
    stack<int> tmp;
    int mini = stk.top();

    // Scan the entire stack to find the minimum value
    while (stk.size())
    {
      mini = min(mini, stk.top());
      tmp.push(stk.top());
      stk.pop();
    }

    // Restore stack elements back from `tmp`
    while (tmp.size())
    {
      stk.push(tmp.top());
      tmp.pop();
    }

    return mini;
  }
};

/*
 * APPROACH-2:  (Using Stack with Min Tracking)
 * - For every `push(val)`, we push a pair `{val, currentMin}`:
 *   - If the stack is empty, the min is the value itself: `{val, val}`.
 *   - Otherwise, `currentMin = min(val, previousMin)`, so that the min remains accessible at all times.
 * - The top of the stack always contains:
 *   - The actual top value (`st.top().first`).
 *   - The minimum so far (`st.top().second`).
 *
 * Dry Run Example:
 * Suppose we push `[5, 3, 7, 2, 6]` into the MinStack.
 *
 * | Action       | Stack Content (`value, min`) |
 * |-------------|----------------------------|
 * | `push(5)`   | `[(5, 5)]` |
 * | `push(3)`   | `[(5, 5), (3, 3)]` |
 * | `push(7)`   | `[(5, 5), (3, 3), (7, 3)]` |
 * | `push(2)`   | `[(5, 5), (3, 3), (7, 3), (2, 2)]` |
 * | `push(6)`   | `[(5, 5), (3, 3), (7, 3), (2, 2), (6, 2)]` |
 *
 * `getMin()` at any point returns the second value of `st.top()`, which is always the minimum in O(1).
 * --------------------
 * T.C: O(n) for n operations → O(1) per operation
 * - push()   → O(1)  (Insert `{val, min(val, st.top().second)}`)
 * - pop()    → O(1)  (Remove top element)
 * - top()    → O(1)  (Access top value)
 * - getMin() → O(1) (Access stored minimum)
 * Overall, for n operations, total time complexity = O(n).
 * --------------------
 * S.C: O(2 * n) → O(n)
 * - Each element stores two values (actual value + min value).
 * - Worst case: If we push n elements, we store 2 * n values.
 * - Since O(2 * n) simplifies to O(n), the overall space complexity remains O(n).
 */
class MinStack
{
public:
  // Stack stores pairs of (value, minimum at that point)
  stack<pair<int, int>> st;

  // Constructor initializes an empty stack
  MinStack() {}

  // Pushes a value onto the stack, updating the current minimum
  void push(int val)
  {
    if (st.empty())
    {
      // First element, min is itself
      st.push({val, val});
    }
    else
    {
      // Push value and update minimum using the top's stored min
      st.push({val, min(val, st.top().second)});
    }
  }

  // Removes the top element from the stack
  void pop()
  {
    st.pop();
  }

  // Returns the top element without removing it
  int top()
  {
    return st.top().first;
  }

  // Returns the minimum element in the stack
  int getMin()
  {
    return st.top().second;
  }
};

/*
 * Approach-3 (Using Two Stacks for Efficient `getMin()`)
 * - We maintain two stacks:
 *   - `stack`: Stores all pushed values.
 *   - `minStack`: Stores the **minimum value** at each level of `stack`.
 * - When pushing:
 *   - Push the value onto `stack`.
 *   - Compute the minimum so far (`min(val, minStack.top())`) and push it onto `minStack`.
 * - When popping:
 *   - Remove elements from both `stack` and `minStack` to maintain synchronization.
 * - `top()` returns the top of `stack`.
 * - `getMin()` returns the top of `minStack`, which **always stores the minimum in O(1)**.
 *
 * Dry Run Example:
 * Suppose we push `[5, 3, 7, 2, 6]` into the MinStack.
 *
 * | Action       | `stack` (values)  | `minStack` (minimums) |
 * |-------------|------------------|-----------------------|
 * | `push(5)`   | `[5]`            | `[5]`                 |
 * | `push(3)`   | `[5,3]`          | `[5,3]`               |
 * | `push(7)`   | `[5,3,7]`        | `[5,3,3]`             |
 * | `push(2)`   | `[5,3,7,2]`      | `[5,3,3,2]`           |
 * | `push(6)`   | `[5,3,7,2,6]`    | `[5,3,3,2,2]`         |
 *
 * Calling `getMin()` at any point returns `minStack.top()`, which is **always the minimum in O(1)**.
 *
 * --------------------
 * T.C: O(1) for all operations
 * - push()   → **O(1)**  (Push value to both stacks)
 * - pop()    → **O(1)**  (Pop from both stacks)
 * - top()    → **O(1)**  (Access top element)
 * - getMin() → **O(1)**  (Access minStack top)
 *
 * Overall, for **n operations**, total time complexity = **O(n)**.
 *
 * --------------------
 * S.C: O(2 * n) → **O(n)**
 * - Two stacks store `n` elements each, leading to **O(2n) → O(n)** space.
 * - `minStack` only **duplicates elements when necessary**, keeping operations optimal.
 * --------------------
 */
class MinStack
{
private:
  // Primary stack for storing values
  std::stack<int> stack;

  // Auxiliary stack to store the minimum values
  std::stack<int> minStack;

public:
  // Constructor initializes an empty stack
  MinStack() {}

  // Pushes a value onto the stack, maintaining the minimum stack
  void push(int val)
  {
    stack.push(val);
    // Compute the minimum so far and push to `minStack`
    val = std::min(val, minStack.empty() ? val : minStack.top());
    minStack.push(val);
  }

  // Removes the top element from both stacks as we maintain the min element as per each level of each in minStack
  void pop()
  {
    stack.pop();
    minStack.pop();
  }

  // Returns the top element of the stack
  int top()
  {
    return stack.top();
  }

  // Returns the minimum element in the stack in O(1)
  int getMin()
  {
    return minStack.top();
  }
};

/*
 * Approach-4 (Using Stack with Encoded Minimum Values)
 * - We maintain a single stack (`st`) and a separate variable `mini` to track the minimum.
 * - Instead of using an extra stack (`minStack`), we **encode** the minimum value directly into `st`.
 * - If the pushed value is **smaller than the current min (`mini`)**, we push an **encoded value**:
 *   - Encoded value = `2 * val - mini`, which helps us retrieve the previous minimum during `pop()`.
 * - `mini` always holds the **smallest element in the stack** at any point.
 * - If the top of the stack (`el`) is **less than `mini`**, it means `el` is encoded, and `mini` needs to be updated.
 *
 * Encoding Formula:
 * - When pushing a new min value `val`:
 *   `Encoded Value = 2 * val - mini`
 * - When popping an encoded value:
 *   `mini = 2 * mini - el`
 *
/*
 * Dry Run Example:
 * Suppose we push the values `[5, 3, 7, 2, 6]` into the MinStack.
 *
 * Step 1: `push(5)`
 * - Since the stack is empty, `mini` is set to `5`, and `5` is pushed onto the stack.
 * - Stack: `[5]`, `mini = 5`
 *
 * Step 2: `push(3)`
 * - Since `3 < mini (5)`, we push the encoded value `2 * 3 - 5 = 1` onto the stack.
 * - `mini` is updated to `3`.
 * - Stack: `[5, 1]`, `mini = 3`
 *
 * Step 3: `push(7)`
 * - Since `7 > mini (3)`, we push `7` as-is onto the stack.
 * - `mini` remains `3`.
 * - Stack: `[5, 1, 7]`, `mini = 3`
 *
 * Step 4: `push(2)`
 * - Since `2 < mini (3)`, we push the encoded value `2 * 2 - 3 = -1` onto the stack.
 * - `mini` is updated to `2`.
 * - Stack: `[5, 1, 7, -1]`, `mini = 2`
 *
 * Step 5: `push(6)`
 * - Since `6 > mini (2)`, we push `6` as-is onto the stack.
 * - `mini` remains `2`.
 * - Stack: `[5, 1, 7, -1, 6]`, `mini = 2`
 *
 * Now, calling `getMin()` at any point returns `mini`, which is always the minimum value in O(1) time.
 * --------------------
 * T.C: O(1) for all operations
 * - push()   → **O(1)**  (Push value or encoded min)
 * - pop()    → **O(1)**  (Retrieve min from encoded value)
 * - top()    → **O(1)**  (Decode if top is encoded)
 * - getMin() → **O(1)**  (Direct access to `mini`)
 *
 * Overall, for **n operations**, total time complexity = **O(n)**.
 *
 * --------------------
 * S.C: O(n)
 * - Uses a **single stack** (`st`), reducing space usage from `O(2n)` to `O(n)`.
 * - The min values are stored **implicitly** using the encoding trick.
 * --------------------
 */
class MinStack
{
private:
  // Stack to store actual values or encoded values
  stack<long long> st;

  // Variable to store the current minimum value
  long long mini;

public:
  // -------------------- Constructor --------------------
  /*
   * Initializes the MinStack.
   * - Clears the stack (though it's empty initially).
   * - Sets `mini` to INT_MAX to track the minimum value.
   */
  MinStack()
  {
    while (!st.empty()) // Ensures stack is empty at initialization
      st.pop();
    mini = INT_MAX; // Initialize the minimum value
  }

  // -------------------- Push Operation --------------------
  /*
   * Pushes a value onto the stack.
   * - If the stack is empty, set `mini` to `val` and push `val` normally.
   * - If `val` is smaller than `mini`, push an **encoded** value (`2 * val - mini`) to track the previous min.
   * - Otherwise, push `val` normally.
   */
  void push(int value)
  {
    long long val = value; // Convert to long long to handle large values

    if (st.empty())
    {
      mini = val;   // First element, set min directly
      st.push(val); // Push normally
    }
    else
    {
      if (val < mini)
      {
        st.push(2 * val - mini); // Push encoded value to track previous min
        mini = val;              // Update mini to the new minimum
      }
      else
      {
        st.push(val); // Push normally if val is not a new min
      }
    }
  }

  // -------------------- Pop Operation --------------------
  /*
   * Removes the top element.
   * - If the popped value is **encoded** (`el < mini`), we restore the previous `mini` using:
   *   `mini = 2 * mini - el`
   * - Otherwise, simply pop without changing `mini`.
   */
  void pop()
  {
    if (st.empty())
      return; // Stack is empty, nothing to pop

    long long el = st.top();
    st.pop();

    if (el < mini) // If encoded value was stored, restore previous min
    {
      mini = 2 * mini - el;
    }
  }

  // -------------------- Top Operation --------------------
  /*
   * Returns the top element.
   * - If the top value is **encoded** (`el < mini`), return `mini` (since encoded values are not actual values).
   * - Otherwise, return `el` normally.
   */
  int top()
  {
    if (st.empty())
      return -1; // If empty, return -1

    long long el = st.top();
    return (el < mini) ? mini : el; // If encoded, return `mini`, else return `el`
  }

  // -------------------- Get Minimum Operation --------------------
  /*
   * Returns the minimum element in **O(1)** time.
   * - `mini` always holds the minimum value in the stack.
   */
  int getMin()
  {
    return mini;
  }
};
