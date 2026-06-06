#include <algorithm>


class Solution {
public:
    int maxArea(std::vector<int>& heightArray) {
        int maxContainerArea = 0;


        int leftIndex = 0;


        int rightIndex = heightArray.size() - 1;


        while (rightIndex != leftIndex) {
            int minHeight = std::min(heightArray[leftIndex], heightArray[rightIndex]);


            int currentArea = (rightIndex - leftIndex) * minHeight;


            maxContainerArea = std::max(maxContainerArea, currentArea);


            if (heightArray[rightIndex] > heightArray[leftIndex]) {
                leftIndex++;
            } else {
                rightIndex--;
            }
        }


        return maxContainerArea;
    }
};
