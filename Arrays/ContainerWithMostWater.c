#include <stdio.h>


int maxArea(int* heightArray, int heightArraySize) {
    int maxContainerArea = 0;


    int leftIndex = 0;


    int rightIndex = heightArraySize - 1;


    while (rightIndex != leftIndex) {
        int minHeight = heightArray[leftIndex] < heightArray[rightIndex] ? 
                        heightArray[leftIndex] : 
                        heightArray[rightIndex];


        int currentArea = (rightIndex - leftIndex) * minHeight;


        if (currentArea > maxContainerArea) {
            maxContainerArea = currentArea;
        }


        if (heightArray[rightIndex] > heightArray[leftIndex]) {
            leftIndex++;
        } 
        else {
            rightIndex--;
        }
    }


    return maxContainerArea;
}
