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
    void dfs(vector<vector<char>>& grid, int currentRow, int currentCol, int totalRows, int totalCols) {
        // Base cases: out of bounds or water
        if (currentRow < 0 || currentRow >= totalRows || currentCol < 0 || currentCol >= totalCols || grid[currentRow][currentCol] == '0') {
            return;
        }
        
        // Mark current cell as visited
        grid[currentRow][currentCol] = '0';
        
        // Explore all 4 directions (up, down, left, right)
        dfs(grid, currentRow - 1, currentCol, totalRows, totalCols);  // up
        dfs(grid, currentRow + 1, currentCol, totalRows, totalCols);  // down
        dfs(grid, currentRow, currentCol - 1, totalRows, totalCols);  // left
        dfs(grid, currentRow, currentCol + 1, totalRows, totalCols);  // right
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        int islandCount = 0;
        
        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < totalCols; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid, i, j, totalRows, totalCols);
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
