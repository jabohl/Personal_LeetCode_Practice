#include <vector>
#include <algorithm>
#include <random>
#include <ctime>


class Solution {
private:
    std::vector<int> originalArray;
    std::vector<int> currentArray;
    std::mt19937 generator;

public:
    Solution(std::vector<int> nums) {
        originalArray = nums;
        currentArray = nums;


        generator.seed(std::time(nullptr));
    }
    

    std::vector<int> reset() {
        currentArray = originalArray;


        return currentArray;
    }
    

    std::vector<int> shuffle() {
        std::vector<int> shuffledArray = currentArray;


        std::shuffle(shuffledArray.begin(), shuffledArray.end(), generator);


        return shuffledArray;
    }
};
