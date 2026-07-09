var maxArea = function(heightArray) {
    let maxContainerArea = 0;


    let inwardMovingPointer = 0;


    let outwardMovingPointer = heightArray.length - 1;


    while (outwardMovingPointer !== inwardMovingPointer) {
        const minPointerYCoordinates = Math.min(heightArray[inwardMovingPointer], heightArray[outwardMovingPointer]);


        const currentContainerArea = (outwardMovingPointer - inwardMovingPointer) * minPointerYCoordinates;


        maxContainerArea = Math.max(maxContainerArea, currentContainerArea);


        if (heightArray[outwardMovingPointer] > heightArray[inwardMovingPointer]) {
            inwardMovingPointer++;
        } else {
            outwardMovingPointer--;
        }
    }


    return maxContainerArea;
};
