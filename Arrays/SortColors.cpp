#include <vector>
#include <algorithm>


class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }


        int currentIndex = 0;


        int zeroPointer = 0;


        int twoPointer = nums.size() - 1;


        while (currentIndex <= twoPointer) {
            if (nums[currentIndex] == 0) {
                std::swap(nums[zeroPointer], nums[currentIndex]);


                currentIndex++;
                zeroPointer++;
            } else if (nums[currentIndex] == 1) {
                currentIndex++;
            } else {
                std::swap(nums[twoPointer], nums[currentIndex]);


                twoPointer--;
            }
        }
    }
};
