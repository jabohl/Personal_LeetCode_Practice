/*
 * LeetCode 130: Surrounded Regions
 * 
 * Problem: Given an m x n matrix board containing 'X' and 'O', capture all regions 
 * surrounded by 'X'. A region is captured by flipping all 'O's into 'X's in that region.
 * 
 * A region is surrounded by 'X' if all its boundaries do not touch the edge of the board.
 * 
 * Approach: Find all 'O' regions that touch the border. These cannot be captured.
 * Mark them as visited, then flip all remaining 'O's to 'X's.
 * 
 * Time Complexity: O(m * n) - visit each cell once
 * Space Complexity: O(m * n) - recursion stack for DFS
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& board, int row, int col, int rows, int cols) {
        // Base cases: out of bounds or already visited or 'X'
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'O') {
            return;
        }
        
        // Mark as visited (using a temporary marker)
        board[row][col] = '#';
        
        // Explore all 4 directions
        dfs(board, row - 1, col, rows, cols);  // up
        dfs(board, row + 1, col, rows, cols);  // down
        dfs(board, row, col - 1, rows, cols);  // left
        dfs(board, row, col + 1, rows, cols);  // right
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Mark all 'O's connected to borders as visited
        // Top and bottom rows
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, rows, cols);
            }
            if (board[rows - 1][j] == 'O') {
                dfs(board, rows - 1, j, rows, cols);
            }
        }
        
        // Left and right columns (skip corners already processed)
        for (int i = 1; i < rows - 1; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, rows, cols);
            }
            if (board[i][cols - 1] == 'O') {
                dfs(board, i, cols - 1, rows, cols);
            }
        }
        
        // Convert all remaining 'O's to 'X's and restore marked cells to 'O'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

// Helper function to print board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Test cases
int main() {
    Solution sol;
    
    // Test case 1: Surrounded region in middle
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X'}
    };
    cout << "Test 1 - Before:\n";
    printBoard(board1);
    sol.solve(board1);
    cout << "After (all O's should be X's):\n";
    printBoard(board1);
    
    // Test case 2: Region connected to border
    vector<vector<char>> board2 = {
        {'X', 'O', 'X'},
        {'X', 'O', 'X'},
        {'X', 'X', 'X'}
    };
    cout << "Test 2 - Before:\n";
    printBoard(board2);
    sol.solve(board2);
    cout << "After (O's on border remain O's):\n";
    printBoard(board2);
    
    // Test case 3: No surrounded regions
    vector<vector<char>> board3 = {
        {'O', 'X', 'O'},
        {'X', 'O', 'X'},
        {'O', 'X', 'O'}
    };
    cout << "Test 3 - Before:\n";
    printBoard(board3);
    sol.solve(board3);
    cout << "After (all O's touch border, remain O's):\n";
    printBoard(board3);
    
    return 0;
}
