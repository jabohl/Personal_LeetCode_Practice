class SmallestInfiniteSet:

    def __init__(self):
        
        
        self.mySet=[]
        
        for index in range(1,1001):
            
            self.mySet.append(index)
        
    def popSmallest(self) -> int:
        
        
        val = self.mySet[0]
        
        
        self.mySet = self.mySet[1:]
        
        
        return val


    def addBack(self, num: int) -> None:
        
        checker=0
        
        checkIn = num not in self.mySet
        
        if checkIn:
            
            for index in range(len(self.mySet)):
                
                if self.mySet[index] >  num:
                    
                    checker = index
                    
                    break
            
            self.mySet.insert(checker,num)
