#include <vector>


class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }


        if (nums.size() == 2) {
            return nums[0] > nums[1] ? 0 : 1;
        }


        if (nums[0] > nums[1]) {
            return 0;
        }


        for (int currentIndex = 1; currentIndex < nums.size() - 1; currentIndex++) {
            if (nums[currentIndex] > nums[currentIndex - 1] && 
                nums[currentIndex] > nums[currentIndex + 1]) {
                return currentIndex;
            }
        }


        if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
            return nums.size() - 1;
        }


        return -1;
    }
};
