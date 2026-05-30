# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, test_list_initial: Optional[ListNode], test_list_final: Optional[ListNode]) -> Optional[ListNode]:
        
        index=0
        
        result=0
        
        while test_list_initial:
            
            result += ( (10**index) * test_list_initial.val )
            
            index += 1
            
            test_list_initial = test_list_initial.next
        
        index=0
        

        
        while test_list_final:
        
            result += ( (10**index) * test_list_final.val)
            
            index += 1
            
            test_list_final = test_list_final.next
        
        
        val = result
        
        node = ListNode(int(str(val)[len(str(val))-1]))
        
        test = node
  
        for index in range(len(str(val))-2,-1,-1):

            node.next = ListNode(int(str(val)[index]))
            
            node=node.next
        
        return test
