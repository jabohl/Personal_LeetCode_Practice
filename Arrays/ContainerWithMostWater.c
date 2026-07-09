#include <stdio.h>


int maxArea(int* heightArray, int heightArraySize) {
    int maxContainerArea = 0;


    int inwardMovingPointer = 0;


    int outwardMovingPointer = heightArraySize - 1;


    while (outwardMovingPointer != inwardMovingPointer) {
        int minPointerYCoordinates = heightArray[inwardMovingPointer] < heightArray[outwardMovingPointer] ? 
                        heightArray[inwardMovingPointer] : 
                        heightArray[outwardMovingPointer];


        int currentContainerArea = (outwardMovingPointer - inwardMovingPointer) * minPointerYCoordinates;


        if (currentContainerArea > maxContainerArea) {
            maxContainerArea = currentContainerArea;
        }


        if (heightArray[outwardMovingPointer] > heightArray[inwardMovingPointer]) {
            inwardMovingPointer++;
        } 
        else {
            outwardMovingPointer--;
        }
    }


    return maxContainerArea;
}
