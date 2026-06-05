# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    """
    Adds two numbers represented as linked lists in reverse order.
    
    Example:
        342 + 465 = 807
        Represented as: 2->4->3 + 5->6->4 = 7->0->8
    
    Time Complexity: O(max(len(firstNumberList), len(secondNumberList)))
    Space Complexity: O(max(len(firstNumberList), len(secondNumberList)))
    """
    
    def addTwoNumbers(self, firstNumberList: Optional[ListNode], secondNumberList: Optional[ListNode]) -> Optional[ListNode]:
        """
        Adds two numbers represented as linked lists by converting to integers,
        summing them, and converting back to a linked list.
        
        Args:
            firstNumberList: First linked list representing a number in reverse
            secondNumberList: Second linked list representing a number in reverse
        
        Returns:
            LinkedList representing the sum in reverse order
        """
        
        # Convert first linked list to integer
        powerOfTen = 0
        firstNumber = 0
        
        currentNode = firstNumberList
        while currentNode:
            # Each digit is multiplied by 10^powerOfTen based on its position
            firstNumber += ((10 ** powerOfTen) * currentNode.val)
            powerOfTen += 1
            currentNode = currentNode.next
        
        # Convert second linked list to integer
        powerOfTen = 0
        secondNumber = 0
        
        currentNode = secondNumberList
        while currentNode:
            secondNumber += ((10 ** powerOfTen) * currentNode.val)
            powerOfTen += 1
            currentNode = currentNode.next
        
        # Sum the two numbers
        totalSum = firstNumber + secondNumber
        
        # Convert sum back to linked list (in reverse order)
        sumStr = str(totalSum)
        
        # Create the head node with the last digit (ones place)
        resultHead = ListNode(int(sumStr[len(sumStr) - 1]))
        currentNode = resultHead
        
        # Build the rest of the linked list
        for digitIndex in range(len(sumStr) - 2, -1, -1):
            currentNode.next = ListNode(int(sumStr[digitIndex]))
            currentNode = currentNode.next
        
        return resultHead
