/**
 * Provides shuffle and reset functionality for an array.
 * Allows shuffling the array and resetting it to the original order.
 * 
 * Time Complexity: O(n) for shuffle, O(n) for reset
 * Space Complexity: O(n) to store the original array
 * 
 * @param {number[]} nums - The original array to shuffle
 */
var Solution = function(nums) {
    // Store a copy of the original array for reset functionality
    this.originalArray = [...nums];
    // Working copy that will be shuffled
    this.currentArray = [...nums];
};

/**
 * Resets the array to its original order.
 * @return {number[]}
 */
Solution.prototype.reset = function() {
    // Restore the current array to the original state
    this.currentArray = [...this.originalArray];
    return this.currentArray;
};

/**
 * Returns a random shuffled version of the array.
 * @return {number[]}
 */
Solution.prototype.shuffle = function() {
    // Create a copy of the current array to shuffle
    const shuffledArray = [...this.currentArray];
    
    // Fisher-Yates shuffle algorithm
    for (let i = shuffledArray.length - 1; i > 0; i--) {
        // Generate random index from 0 to i (inclusive)
        const randomIndex = Math.floor(Math.random() * (i + 1));
        
        // Swap elements at i and randomIndex
        [shuffledArray[i], shuffledArray[randomIndex]] = 
        [shuffledArray[randomIndex], shuffledArray[i]];
    }
    
    return shuffledArray;
};

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */
