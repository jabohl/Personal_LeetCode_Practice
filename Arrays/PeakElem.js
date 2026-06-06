var findPeakElement = function(nums) {
    if (nums.length === 1) {
        return 0;
    }


    if (nums.length === 2) {
        return nums[0] > nums[1] ? 0 : 1;
    }


    if (nums[0] > nums[1]) {
        return 0;
    }


    for (let currentIndex = 1; currentIndex < nums.length - 1; currentIndex++) {
        if (nums[currentIndex] > nums[currentIndex - 1] && 
            nums[currentIndex] > nums[currentIndex + 1]) {
            return currentIndex;
        }
    }


    if (nums[nums.length - 1] > nums[nums.length - 2]) {
        return nums.length - 1;
    }


    return -1;
};
