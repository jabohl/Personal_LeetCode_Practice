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
        
        rows, cols = len(rooms), len(rooms[0])
        queue = deque()
        INF = 2147483647
        
        # Find all gates and add to queue
        for i in range(rows):
            for j in range(cols):
                if rooms[i][j] == 0:
                    queue.append((i, j))
        
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        # BFS from all gates
        while queue:
            row, col = queue.popleft()
            
            # Check all 4 adjacent cells
            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc
                
                if (0 <= new_row < rows and 
                    0 <= new_col < cols and 
                    rooms[new_row][new_col] == INF):
                    rooms[new_row][new_col] = rooms[row][col] + 1
                    queue.append((new_row, new_col))


# Test cases
if __name__ == "__main__":
    solution = Solution()
    INF = 2147483647
    
    # Test case 1: Example case
    rooms1 = [
        [INF, -1, 0, INF],
        [INF, INF, INF, -1],
        [INF, -1, INF, -1],
        [0, -1, INF, INF]
    ]
    solution.wallsAndGates(rooms1)
    print("Test 1:")
    for row in rooms1:
        print([x if x != INF else 'INF' for x in row])
    # Expected:
    # [3, -1, 0, 1]
    # [2, 2, 1, -1]
    # [1, -1, 2, -1]
    # [0, -1, 3, 4]
    
    print()
    
    # Test case 2: Single gate
    rooms2 = [
        [INF, INF],
        [0, INF]
    ]
    solution.wallsAndGates(rooms2)
    print("Test 2:")
    for row in rooms2:
        print(row)
    # Expected:
    # [2, 1]
    # [0, 1]
    
    print()
    
    # Test case 3: All gates
    rooms3 = [
        [0, 0],
        [0, 0]
    ]
    solution.wallsAndGates(rooms3)
    print("Test 3:")
    for row in rooms3:
        print(row)
    # Expected:
    # [0, 0]
    # [0, 0]
    
    print()
    
    # Test case 4: Room surrounded by walls
    rooms4 = [
        [0, INF, -1],
        [-1, INF, -1],
        [-1, INF, 0]
    ]
    solution.wallsAndGates(rooms4)
    print("Test 4:")
    for row in rooms4:
        print([x if x != INF else 'INF' for x in row])
    # Expected:
    # [0, 1, -1]
    # [-1, 2, -1]
    # [-1, 1, 0]
