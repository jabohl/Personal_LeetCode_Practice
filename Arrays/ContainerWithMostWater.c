#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int maxContainer = 0, index = 0, minHeight, maxTest;

    
    int i2 = heightSize - 1;
    
    
    while (i2 != index) {
    
        minHeight = height[index] < height[i2] ? height[index] : height[i2];
        
        maxTest = (i2 - index) * minHeight;
        
        
        
        if (maxTest > maxContainer) {
            maxContainer = maxTest;
        }
        
        
        
        if (height[i2] > height[index]) {
            index++ ;
        } 
        
        
        
        else {
            i2-- ;
        }
    }

    
    
    return maxContainer;


}
