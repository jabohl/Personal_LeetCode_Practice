#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    static int resultIndices[2];


    *returnSize = 2;


    for (int firstIndex = 0; firstIndex < numsSize - 1; firstIndex++) {
        for (int secondIndex = firstIndex + 1; secondIndex < numsSize; secondIndex++) {
            if (nums[firstIndex] + nums[secondIndex] == target) {
                resultIndices[0] = firstIndex;
                resultIndices[1] = secondIndex;


                return resultIndices;           
            }
        }
    }


    return NULL;
}
