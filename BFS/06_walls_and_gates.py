"""
Problem: Walls and Gates
URL: https://leetcode.com/problems/walls-and-gates/

Description:
You are given an m x n grid initialized with three possible values:
- -1: A wall or obstacle
- 0: A gate
- INF: Infinity means an empty room

Fill each empty room with the distance to its nearest gate. If it is impossible 
to reach a gate, it should remain INF.

Example:
    Input: room = [
      [INF, -1,  0,  INF],
      [INF, INF, INF, -1],
      [INF, -1, INF, -1],
      [0,   -1, INF, INF]
    ]
    Output: [
      [3, -1, 0, 1],
      [2,  2, 1, -1],
      [1, -1, 2, -1],
      [0, -1, 3,  4]
    ]
"""

from collections import deque
from typing import List


class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Solve using multi-source BFS from all gates.
        
        Approach:
        1. Initialize queue with all gates (cells with value 0)
        2. Use multi-source BFS to spread outward from all gates simultaneously
        3. Update distance for each empty room visited
        4. Modifies the input grid in-place
        
        Time Complexity: O(m * n)
        Space Complexity: O(m * n) for the queue
        """
        if not rooms or not rooms[0]:
            return
        
        totalRows, totalCols = len(rooms), len(rooms[0])
        gateQueue = deque()
        INFINITY_VALUE = 2147483647
        
        # Find all gates and add to queue
        for rowIndex in range(totalRows):
            for colIndex in range(totalCols):
                if rooms[rowIndex][colIndex] == 0:
                    gateQueue.append((rowIndex, colIndex))
        
        directionOffsets = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        # BFS from all gates
        while gateQueue:
            currentRow, currentCol = gateQueue.popleft()
            
            # Check all 4 adjacent cells
            for rowOffset, colOffset in directionOffsets:
                neighborRow, neighborCol = currentRow + rowOffset, currentCol + colOffset
                
                if (0 <= neighborRow < totalRows and 
                    0 <= neighborCol < totalCols and 
                    rooms[neighborRow][neighborCol] == INFINITY_VALUE):
                    rooms[neighborRow][neighborCol] = rooms[currentRow][currentCol] + 1
                    gateQueue.append((neighborRow, neighborCol))


# Test cases
if __name__ == "__main__":
    solution = Solution()
    INFINITY_VALUE = 2147483647
    
    # Test case 1: Example case
    rooms1 = [
        [INFINITY_VALUE, -1, 0, INFINITY_VALUE],
        [INFINITY_VALUE, INFINITY_VALUE, INFINITY_VALUE, -1],
        [INFINITY_VALUE, -1, INFINITY_VALUE, -1],
        [0, -1, INFINITY_VALUE, INFINITY_VALUE]
    ]
    solution.wallsAndGates(rooms1)
    print("Test 1:")
    for row in rooms1:
        print([x if x != INFINITY_VALUE else 'INF' for x in row])
    # Expected:
    # [3, -1, 0, 1]
    # [2, 2, 1, -1]
    # [1, -1, 2, -1]
    # [0, -1, 3, 4]
    
