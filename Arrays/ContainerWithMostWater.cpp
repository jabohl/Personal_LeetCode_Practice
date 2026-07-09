#include <algorithm>


class Solution {
public:
    int maxArea(std::vector<int>& heightArray) {
        int maxContainerArea = 0;


        int inwardMovingPointer = 0;


        int outwardMovingPointer = heightArray.size() - 1;


        while (outwardMovingPointer != inwardMovingPointer) {
            int minPointerYCoordinates = std::min(heightArray[inwardMovingPointer], heightArray[outwardMovingPointer]);


            int currentContainerArea = (outwardMovingPointer - inwardMovingPointer) * minPointerYCoordinates;


            maxContainerArea = std::max(maxContainerArea, currentContainerArea);


            if (heightArray[outwardMovingPointer] > heightArray[inwardMovingPointer]) {
                inwardMovingPointer++;
            } else {
                outwardMovingPointer--;
            }
        }


        return maxContainerArea;
    }
};
