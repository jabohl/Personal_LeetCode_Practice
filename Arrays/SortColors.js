var sortColors = function(nums) {
    if (nums.length < 2) {
        return;
    }


    let currentIndex = 0;


    let zeroPointer = 0;


    let twoPointer = nums.length - 1;


    while (currentIndex <= twoPointer) {
        if (nums[currentIndex] === 0) {
            [nums[zeroPointer], nums[currentIndex]] = 
            [nums[currentIndex], nums[zeroPointer]];


            currentIndex++;
            zeroPointer++;
        } else if (nums[currentIndex] === 1) {
            currentIndex++;
        } else {
            [nums[twoPointer], nums[currentIndex]] = 
            [nums[currentIndex], nums[twoPointer]];


            twoPointer--;
        }
    }
};
