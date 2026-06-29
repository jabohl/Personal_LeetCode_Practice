var maxArea = function(heightArray) {
    let maxContainerArea = 0;


    let leftPointerIndex = 0;


    let rightPointerIndex = heightArray.length - 1;


    while (rightPointerIndex !== leftPointerIndex) {
        const minHeight = Math.min(heightArray[leftPointerIndex], heightArray[rightPointerIndex]);


        const currentContainerArea = (rightPointerIndex - leftPointerIndex) * minHeight;


        maxContainerArea = Math.max(maxContainerArea, currentContainerArea);


        if (heightArray[rightPointerIndex] > heightArray[leftPointerIndex]) {
            leftPointerIndex++;
        } else {
            rightPointerIndex--;
        }
    }


    return maxContainerArea;
};
