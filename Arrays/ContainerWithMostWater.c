#include <stdio.h>

/**
 * Finds the maximum area of water that can be contained between two lines.
 * Uses two-pointer approach to efficiently find the best container.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * @param heightArray Array of integers representing the height of lines
 * @param heightArraySize Size of the height array
 * @return The maximum area of water that can be contained
 */
int maxArea(int* heightArray, int heightArraySize) {
    /* Track the maximum area found so far */
    int maxContainerArea = 0;
    
    /* Left pointer starts at the beginning of the array */
    int leftIndex = 0;
    
    /* Right pointer starts at the end of the array */
    int rightIndex = heightArraySize - 1;
    
    /* Continue until the two pointers meet */
    while (rightIndex != leftIndex) {
        /* Find the minimum height between the two lines */
        /* The container height is limited by the shorter line */
        int minHeight = heightArray[leftIndex] < heightArray[rightIndex] ? 
                        heightArray[leftIndex] : 
                        heightArray[rightIndex];
        
        /* Calculate the area with current left and right pointers */
        /* Area = width * height */
        int currentArea = (rightIndex - leftIndex) * minHeight;
        
        /* Update maxContainerArea if current area is larger */
        if (currentArea > maxContainerArea) {
            maxContainerArea = currentArea;
        }
        
        /* Move the pointer pointing to the shorter line inward */
        /* This maximizes the chance of finding a taller line */
        if (heightArray[rightIndex] > heightArray[leftIndex]) {
            leftIndex++;
        } 
        else {
            rightIndex--;
        }
    }
    
    /* Return the maximum area found */
    return maxContainerArea;
}
