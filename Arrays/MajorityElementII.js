var majorityElement = function(nums) {
    const elementFrequencyMap = new Map();


    for (const num of nums) {
        elementFrequencyMap.set(num, (elementFrequencyMap.get(num) || 0) + 1);
    }


    const majorityElements = [];


    for (const [num, count] of elementFrequencyMap) {
        if (count > Math.floor(nums.length / 3)) {
            majorityElements.push(num);
        }
    }


    return majorityElements;
};
