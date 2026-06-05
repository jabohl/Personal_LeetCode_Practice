"""
Problem: Course Schedule
URL: https://leetcode.com/problems/course-schedule/

Description:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you 
must take course bi first if you want to take course ai.

Return true if you can finish all courses. Otherwise, return false.

This is a classic cycle detection problem in a directed graph. Can be solved using:
- BFS (Kahn's Algorithm - Topological Sort)
- DFS

Example:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
    Explanation: Take course 0 first, then course 1.
    
    Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    Output: false
    Explanation: Circular dependency, impossible to complete.
"""

from collections import deque, defaultdict
from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        """
        Solve using Kahn's Algorithm (BFS-based Topological Sort).
        
        Approach:
        1. Build adjacency list and calculate in-degree for each course
        2. Add all courses with in-degree 0 to queue (no prerequisites)
        3. Process courses level by level, reducing in-degree of dependent courses
        4. If we can process all courses, no cycle exists
        5. If we can't process all courses, a cycle exists
        
        Time Complexity: O(V + E) where V is courses and E is prerequisites
        Space Complexity: O(V + E) for graph storage and queue
        """
        # Build graph and in-degree array
        in_degree = [0] * numCourses
        graph = defaultdict(list)
        
        for course, prerequisite in prerequisites:
            graph[prerequisite].append(course)
            in_degree[course] += 1
        
        # Queue contains all courses with no prerequisites
        queue = deque()
        for i in range(numCourses):
            if in_degree[i] == 0:
                queue.append(i)
        
        completed_courses = 0
        
        # Process courses with no prerequisites
        while queue:
            current_course = queue.popleft()
            completed_courses += 1
            
            # For all courses that depend on current_course
            for next_course in graph[current_course]:
                in_degree[next_course] -= 1
                
                # If all prerequisites are completed, add to queue
                if in_degree[next_course] == 0:
                    queue.append(next_course)
        
        # If we completed all courses, no cycle exists
        return completed_courses == numCourses


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test case 1: Simple dependency
    print("Test 1:", solution.canFinish(2, [[1, 0]]))
    # Expected: True (can take course 0, then course 1)
    
    # Test case 2: Circular dependency
    print("Test 2:", solution.canFinish(2, [[1, 0], [0, 1]]))
    # Expected: False (circular dependency)
    
    # Test case 3: No prerequisites
    print("Test 3:", solution.canFinish(3, []))
    # Expected: True (can take all courses)
    
    # Test case 4: Complex dependency chain
    print("Test 4:", solution.canFinish(4, [[1, 0], [2, 1], [3, 2]]))
    # Expected: True (0 -> 1 -> 2 -> 3)
    
    # Test case 5: Multiple paths with cycle
    print("Test 5:", solution.canFinish(3, [[0, 1], [0, 2], [1, 2], [2, 1]]))
    # Expected: False (1 and 2 have circular dependency)
    
    # Test case 6: Large chain
    print("Test 6:", solution.canFinish(5, [[1, 0], [2, 1], [3, 2], [4, 3]]))
    # Expected: True
