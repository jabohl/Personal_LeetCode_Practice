/*
 * LeetCode 200: Number of Islands
 * 
 * Problem: Given an m x n 2D binary grid grid which represents a map of '1's (land) 
 * and '0's (water), return the number of islands.
 * 
 * An island is surrounded by water and is formed by connecting adjacent lands 
 * horizontally or vertically. You may assume all four edges of the grid are surrounded 
 * by water.
 * 
 * Time Complexity: O(m * n) - visit each cell once
 * Space Complexity: O(m * n) - recursion stack for DFS
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int row, int col, int rows, int cols) {
        // Base cases: out of bounds or water
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') {
            return;
        }
        
        // Mark current cell as visited
        grid[row][col] = '0';
        
        // Explore all 4 directions (up, down, left, right)
        dfs(grid, row - 1, col, rows, cols);  // up
        dfs(grid, row + 1, col, rows, cols);  // down
        dfs(grid, row, col - 1, rows, cols);  // left
        dfs(grid, row, col + 1, rows, cols);  // right
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        
        return islandCount;
    }
};

// Test cases
int main() {
    Solution sol;
    
    // Test case 1: Multiple islands
    vector<vector<char>> grid1 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << "Test 1 - Expected: 3, Got: " << sol.numIslands(grid1) << endl;
    
    // Test case 2: Single island
    vector<vector<char>> grid2 = {
        {'1', '1', '1'},
        {'0', '1', '0'},
        {'1', '1', '1'}
    };
    cout << "Test 2 - Expected: 1, Got: " << sol.numIslands(grid2) << endl;
    
    // Test case 3: All water
    vector<vector<char>> grid3 = {
        {'0', '0', '0'},
        {'0', '0', '0'}
    };
    cout << "Test 3 - Expected: 0, Got: " << sol.numIslands(grid3) << endl;
    
    return 0;
}
