/**
 * Finds all elements that appear more than n/3 times in the array.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) for the hash map
 * 
 * @param {number[]} nums - Array of integers
 * @return {number[]} - List of integers that appear more than n/3 times
 */
var majorityElement = function(nums) {
    // Map to store frequency of each element
    const elementFrequencyMap = new Map();
    
    // Count the frequency of each element
    for (const num of nums) {
        elementFrequencyMap.set(num, (elementFrequencyMap.get(num) || 0) + 1);
    }
    
    // Array to store elements that appear more than n/3 times
    const majorityElements = [];
    
    // Check which elements appear more than n/3 times
    for (const [num, count] of elementFrequencyMap) {
        if (count > Math.floor(nums.length / 3)) {
            majorityElements.push(num);
        }
    }
    
    return majorityElements;
};
