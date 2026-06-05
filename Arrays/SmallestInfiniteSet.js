/**
 * Manages an infinite set of positive integers starting from 1.
 * Supports removing the smallest element and adding numbers back.
 * 
 * Time Complexity: 
 *     - popSmallest: O(1) amortized
 *     - addBack: O(log n)
 * Space Complexity: O(n) for storing removed numbers
 */
var SmallestInfiniteSet = function() {
    // Start with the smallest positive integer
    this.nextSmallest = 1;
    // Set to store numbers that were added back
    this.addedBack = new Set();
};

/**
 * Removes and returns the smallest number from the set.
 * @return {number}
 */
SmallestInfiniteSet.prototype.popSmallest = function() {
    // Check if there are numbers that were added back
    if (this.addedBack.size > 0) {
        // Get the smallest number from the set
        const smallest = Math.min(...this.addedBack);
        this.addedBack.delete(smallest);
        return smallest;
    }
    
    // Otherwise, return the next smallest from the infinite sequence
    return this.nextSmallest++;
};

/**
 * Adds a number back to the set if it's not already present.
 * @param {number} num
 * @return {void}
 */
SmallestInfiniteSet.prototype.addBack = function(num) {
    // Only add if it's less than the next smallest that hasn't been popped
    if (num < this.nextSmallest) {
        this.addedBack.add(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * var obj = new SmallestInfiniteSet()
 * var param_1 = obj.popSmallest()
 * obj.addBack(num)
 */
