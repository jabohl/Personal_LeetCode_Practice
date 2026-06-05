/**
 * Finds two numbers in the array that add up to the target value.
 * Uses brute force approach checking all pairs.
 * 
 * Time Complexity: O(n^2) - nested loops through entire array
 * Space Complexity: O(1) - only using constant extra space
 * 
 * @param {number[]} nums - Array of integers to search
 * @param {number} target - The target sum
 * @return {number[]} - Array of two indices whose values sum to target
 */
var twoSum = function(nums, target) {
    // Outer loop: iterate through each element
    for (let firstIndex = 0; firstIndex < nums.length - 1; firstIndex++) {
        // Inner loop: check all elements after firstIndex
        for (let secondIndex = firstIndex + 1; secondIndex < nums.length; secondIndex++) {
            // Check if the sum of two elements equals the target
            if (nums[firstIndex] + nums[secondIndex] === target) {
                // Return the indices immediately upon finding a solution
                return [firstIndex, secondIndex];
            }
        }
    }
    
    // Return empty array if no pair is found
    return [];
};
