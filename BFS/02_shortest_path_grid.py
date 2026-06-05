"""
Problem: Shortest Path in a Grid (0/1 Matrix)
URL: https://leetcode.com/problems/01-matrix/

Description:
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example:
    Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
    Output: [[0,0,0],[0,1,0],[1,2,1]]
"""

from collections import deque
from typing import List


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        """
        Solve using multi-source BFS.
        
        Approach:
        1. Start BFS from all 0 cells simultaneously (multi-source BFS)
        2. Use a queue to track cells and their distances
        3. For each cell, explore all 4 adjacent cells (up, down, left, right)
        4. Mark visited cells to avoid revisiting
        
        Time Complexity: O(m * n) where m and n are dimensions of the matrix
        Space Complexity: O(m * n) for the queue and distance matrix
        """
        if not mat or not mat[0]:
            return mat
        
        rows, cols = len(mat), len(mat[0])
        queue = deque()
        visited = [[False] * cols for _ in range(rows)]
        
        # Initialize: add all 0 cells to the queue
        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 0:
                    queue.append((i, j, 0))
                    visited[i][j] = True
        
        # Directions: up, down, left, right
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        # BFS from all 0 cells
        while queue:
            row, col, dist = queue.popleft()
            mat[row][col] = dist
            
            # Explore all 4 adjacent cells
            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc
                
                # Check boundaries and if not visited
                if 0 <= new_row < rows and 0 <= new_col < cols and not visited[new_row][new_col]:
                    visited[new_row][new_col] = True
                    queue.append((new_row, new_col, dist + 1))
        
        return mat


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test case 1
    mat1 = [[0, 0, 0], [0, 1, 0], [1, 1, 1]]
    result1 = solution.updateMatrix(mat1)
    print("Test 1:")
    for row in result1:
        print(row)
    # Expected:
    # [0, 0, 0]
    # [0, 1, 0]
    # [1, 2, 1]
    
    print()
    
    # Test case 2
    mat2 = [[0, 0], [1, 1]]
    result2 = solution.updateMatrix(mat2)
    print("Test 2:")
    for row in result2:
        print(row)
    # Expected:
    # [0, 0]
    # [1, 1]
    
    print()
    
    # Test case 3
    mat3 = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    result3 = solution.updateMatrix(mat3)
    print("Test 3:")
    for row in result3:
        print(row)
    # Expected:
    # [2, 1, 2]
    # [1, 0, 1]
    # [2, 1, 2]
