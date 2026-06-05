#include <stdio.h>
#include <stdlib.h>

/**
 * Finds two numbers in the array that add up to the target value.
 * Uses brute force approach checking all pairs.
 * 
 * Time Complexity: O(n^2) - nested loops through entire array
 * Space Complexity: O(1) - only using constant extra space
 * 
 * @param nums Array of integers to search
 * @param numsSize Size of the nums array
 * @param target The target sum
 * @param returnSize Pointer to store the size of the result (will be 2)
 * @return Array of two indices whose values sum to target, or NULL if not found
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    /* Static array to store the result indices */
    static int resultIndices[2];
    
    /* Result will always have 2 elements */
    *returnSize = 2;
    
    /* Outer loop: iterate through each element */
    for (int firstIndex = 0; firstIndex < numsSize - 1; firstIndex++) {
        /* Inner loop: check all elements after firstIndex */
        for (int secondIndex = firstIndex + 1; secondIndex < numsSize; secondIndex++) {
            /* Check if the sum of two elements equals the target */
            if (nums[firstIndex] + nums[secondIndex] == target) {
                /* Store the indices in the result array */
                resultIndices[0] = firstIndex;
                resultIndices[1] = secondIndex;
                
                /* Return the result immediately upon finding a solution */
                return resultIndices;           
            }
        }
    }
    
    /* Return NULL if no pair is found that sums to target */
    return NULL;
}
