#include <stdio.h>


int maxArea(int* heightArray, int heightArraySize) {
    int maxContainerArea = 0;


    int leftPointerIndex = 0;


    int rightPointerIndex = heightArraySize - 1;


    while (rightPointerIndex != leftPointerIndex) {
        int minHeight = heightArray[leftPointerIndex] < heightArray[rightPointerIndex] ? 
                        heightArray[leftPointerIndex] : 
                        heightArray[rightPointerIndex];


        int currentContainerArea = (rightPointerIndex - leftPointerIndex) * minHeight;


        if (currentContainerArea > maxContainerArea) {
            maxContainerArea = currentContainerArea;
        }


        if (heightArray[rightPointerIndex] > heightArray[leftPointerIndex]) {
            leftPointerIndex++;
        } 
        else {
            rightPointerIndex--;
        }
    }


    return maxContainerArea;
}
