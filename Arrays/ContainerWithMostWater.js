var maxArea = function(heightArray) {
    let maxContainerArea = 0;


    let leftIndex = 0;


    let rightIndex = heightArray.length - 1;


    while (rightIndex !== leftIndex) {
        const minHeight = Math.min(heightArray[leftIndex], heightArray[rightIndex]);


        const currentArea = (rightIndex - leftIndex) * minHeight;


        maxContainerArea = Math.max(maxContainerArea, currentArea);


        if (heightArray[rightIndex] > heightArray[leftIndex]) {
            leftIndex++;
        } else {
            rightIndex--;
        }
    }


    return maxContainerArea;
};
