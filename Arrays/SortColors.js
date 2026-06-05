/**
 * Sorts an array containing only 0s, 1s, and 2s in-place.
 * Uses a three-pointer approach to separate the colors.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * @param {number[]} nums - List of integers containing only 0, 1, and 2
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    // Handle edge cases
    if (nums.length < 2) {
        return;
    }
    
    // Pointer for current element being examined
    let currentIndex = 0;
    // Pointer for position where 0s should be placed
    let zeroPointer = 0;
    // Pointer for position where 2s should be placed
    let twoPointer = nums.length - 1;
    
    // Continue until currentIndex reaches the twoPointer
    while (currentIndex <= twoPointer) {
        if (nums[currentIndex] === 0) {
            // Swap current element with element at zeroPointer
            [nums[zeroPointer], nums[currentIndex]] = 
            [nums[currentIndex], nums[zeroPointer]];
            currentIndex++;
            zeroPointer++;
        } else if (nums[currentIndex] === 1) {
            // 1 is already in correct partition, just move forward
            currentIndex++;
        } else {  // nums[currentIndex] === 2
            // Swap current element with element at twoPointer
            [nums[twoPointer], nums[currentIndex]] = 
            [nums[currentIndex], nums[twoPointer]];
            // Don't increment currentIndex yet, we need to check the swapped element
            twoPointer--;
        }
    }
};
