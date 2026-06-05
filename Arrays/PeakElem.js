/**
 * Finds a peak element in the array.
 * A peak element is an element that is strictly greater than its neighbors.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * @param {number[]} nums - Array of integers
 * @return {number} - Index of a peak element
 */
var findPeakElement = function(nums) {
    // Handle edge case: array with single element
    if (nums.length === 1) {
        return 0;
    }
    
    // Handle edge case: array with two elements
    if (nums.length === 2) {
        return nums[0] > nums[1] ? 0 : 1;
    }
    
    // Check if the first element is a peak (greater than its right neighbor)
    if (nums[0] > nums[1]) {
        return 0;
    }
    
    // Check all interior elements
    for (let currentIndex = 1; currentIndex < nums.length - 1; currentIndex++) {
        // A peak must be greater than both left and right neighbors
        if (nums[currentIndex] > nums[currentIndex - 1] && 
            nums[currentIndex] > nums[currentIndex + 1]) {
            return currentIndex;
        }
    }
    
    // Check if the last element is a peak (greater than its left neighbor)
    if (nums[nums.length - 1] > nums[nums.length - 2]) {
        return nums.length - 1;
    }
    
    return -1;
};
