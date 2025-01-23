#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Naive and simplest using 3 iterations of the Sudoku board)
 * ---------------------------------------------------
 * The algorithm checks if a given Sudoku board is valid by validating:
 * 1. All rows contain unique numbers (ignoring '.').
 * 2. All columns contain unique numbers (ignoring '.').
 * 3. Each of the 3x3 sub-boxes contains unique numbers (ignoring '.').
 *
 * - For row and column validation: Iterate through the board row-wise and column-wise while using a hash set to track seen numbers.
 * - For sub-box validation: Iterate over each 3x3 box using a helper function `validSub` to check the uniqueness of numbers.
 * ---------------------------------------------------
 * Time Complexity (TC): O(3 * 9 * 9) = O(243) ≈ O(1)
 * - Validating rows: O(9 * 9) = O(81).
 * - Validating columns: O(9 * 9) = O(81).
 * - Validating sub-boxes: O(9 * 9) = O(81).
 * ---------------------------------------------------
 * Space Complexity (SC): O(9) ≈ O(1)
 * - We use an unordered_set for each row, column, and sub-box validation, which requires O(9) space.
 */

class Solution
{
public:
  // Helper function to validate a 3x3 sub-box
  bool validSub(vector<vector<char>> &board, int sr, int er, int sc, int ec)
  {
    // Create a set to track numbers in the 3x3 box
    unordered_set<char> st;
    // Iterate over the rows and columns within the box
    for (int row = sr; row <= er; row++)
    {
      for (int col = sc; col <= ec; col++)
      {
        char ch = board[row][col];
        // Ignore empty cells
        if (ch == '.')
          continue;
        // Check if the number is already in the set
        if (st.count(ch))
          return false;
        // Add the number to the set
        st.insert(ch);
      }
    }
    // All numbers are unique in this box
    return true;
  }

  bool isValidSudoku(vector<vector<char>> &board)
  {
    // Validate rows
    for (int row = 0; row < 9; row++)
    {
      // Set to track numbers in the current row
      unordered_set<char> st;
      for (int col = 0; col < 9; col++)
      {
        char ch = board[row][col];
        // Ignore empty cells
        if (ch == '.')
          continue;
        // Check if the number is already in the set
        if (st.count(ch))
          return false;
        // Add the number to the set
        st.insert(ch);
      }
    }

    // Validate columns
    for (int col = 0; col < 9; col++)
    {
      // Set to track numbers in the current column
      unordered_set<char> st;
      for (int row = 0; row < 9; row++)
      {
        char ch = board[row][col];
        // Ignore empty cells
        if (ch == '.')
          continue;
        // Check if the number is already in the set
        if (st.count(ch))
          return false;
        // Add the number to the set
        st.insert(ch);
      }
    }

    // Validate each 3x3 sub-box
    for (int sr = 0; sr < 9; sr += 3)
    {
      int er = sr + 2; // Calculate the end row for the current box
      for (int sc = 0; sc < 9; sc += 3)
      {
        int ec = sc + 2; // Calculate the end column for the current box
        // Validate the current 3x3 box
        if (!validSub(board, sr, er, sc, ec))
          return false;
      }
    }

    // The board is valid if all checks pass
    return true;
  }
};

/*
 * Approach-2 (One iteration using hashmap and indexing boxes)
 * -----------------------------------------------------------
 * Time Complexity: O(9 * 9) = O(81) = O(1)
 * - We iterate through all 81 cells in the 9x9 Sudoku board once.
 * - Operations such as insertion and lookup in the unordered_set are O(1) on average.
 *
 * Space Complexity: O(3 * 9 * 9) = O(243) = O(1)
 * - We store at most 3 strings (for row, column, and box) for each cell in the set.
 * - Each string is small and constant in size.
 */
class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    // Initialize an unordered_set to track unique constraints
    unordered_set<string> st;

    // Iterate through each cell in the 9x9 Sudoku board
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        // Skip empty cells represented by '.'
        if (board[i][j] == '.')
          continue;

        // Create unique identifiers for row, column, and 3x3 box constraints
        string row = string(1, board[i][j]) + "_row_" + to_string(i);
        string col = string(1, board[i][j]) + "_col_" + to_string(j);
        string box = string(1, board[i][j]) + "_box_" + to_string(i / 3) + "_" + to_string(j / 3);

        // Check if any of these identifiers already exist in the set
        if (st.count(row) || st.count(col) || st.count(box))
        {
          return false; // Constraint violated, return false
        }

        // Add the identifiers to the set
        st.insert(row);
        st.insert(col);
        st.insert(box);
      }
    }

    // If no violations are found, the board is valid
    return true;
  }
};
