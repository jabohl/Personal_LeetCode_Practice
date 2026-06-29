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
        
        totalRows, totalCols = len(mat), len(mat[0])
        cellQueue = deque()
        visitedCells = [[False] * totalCols for _ in range(totalRows)]
        
        # Initialize: add all 0 cells to the queue
        for rowIndex in range(totalRows):
            for colIndex in range(totalCols):
                if mat[rowIndex][colIndex] == 0:
                    cellQueue.append((rowIndex, colIndex, 0))
                    visitedCells[rowIndex][colIndex] = True
        
        # Directions: up, down, left, right
        directionOffsets = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        # BFS from all 0 cells
        while cellQueue:
            currentRow, currentCol, currentDistance = cellQueue.popleft()
            mat[currentRow][currentCol] = currentDistance
            
            # Explore all 4 adjacent cells
            for rowOffset, colOffset in directionOffsets:
                neighborRow, neighborCol = currentRow + rowOffset, currentCol + colOffset
                
                # Check boundaries and if not visited
                if 0 <= neighborRow < totalRows and 0 <= neighborCol < totalCols and not visitedCells[neighborRow][neighborCol]:
                    visitedCells[neighborRow][neighborCol] = True
                    cellQueue.append((neighborRow, neighborCol, currentDistance + 1))
        
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
