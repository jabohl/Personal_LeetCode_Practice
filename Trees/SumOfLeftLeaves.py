# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        
        lefts, list_of_lefts= [ ], [ [root] ]
        
        index, sum = 0, 0
        

        
        while len(list_of_lefts[index]) > 0:
        
            myList=[]
            
            
            
            for index2 in range(len(list_of_lefts[index])):   
            
            
                
                if list_of_lefts[index][index2].left is not None:
                    
                    lefts.append(list_of_lefts[index][index2].left)
                    myList.append(list_of_lefts[index][index2].left)
                
                
                
                
                if list_of_lefts[index][index2].right is not None:
                    
                    myList.append(list_of_lefts[index][index2].right)
            
            
            
            
            
            list_of_lefts.append(myList)
            
            index += 1
            

        
        for index in range(len(lefts)):
        
            if lefts[index].left is None and lefts[index].right is None:
                sum += lefts[index].val
        
        
        return sum
