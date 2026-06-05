/**
 * Definition for singly-linked list.
 * function ListNode(val, next = null) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

/**
 * Adds two numbers represented as linked lists in reverse order.
 * 
 * For example:
 *   342 + 465 = 807
 *   Represented as: 2->4->3 + 5->6->4 = 7->0->8
 * 
 * Time Complexity: O(max(len(firstNumberList), len(secondNumberList)))
 * Space Complexity: O(max(len(firstNumberList), len(secondNumberList))) for the result list
 * 
 * @param {ListNode} firstNumberList - First linked list representing a number in reverse
 * @param {ListNode} secondNumberList - Second linked list representing a number in reverse
 * @return {ListNode} - Linked list representing the sum in reverse order
 */
var addTwoNumbers = function(firstNumberList, secondNumberList) {
    // Initialize carry for digit addition
    let carry = 0;
    
    // Create a dummy head node to simplify list construction
    const dummyHead = new ListNode(0);
    let currentTail = dummyHead;
    
    // Continue processing while there are digits in either list or a carry remains
    while (firstNumberList !== null || secondNumberList !== null || carry !== 0) {
        // Start with the carry from the previous digit addition
        let digitSum = carry;
        
        // Add the digit from the first list if it exists
        if (firstNumberList !== null) {
            digitSum += firstNumberList.val;
            firstNumberList = firstNumberList.next;
        }
        
        // Add the digit from the second list if it exists
        if (secondNumberList !== null) {
            digitSum += secondNumberList.val;
            secondNumberList = secondNumberList.next;
        }
        
        // Calculate carry for the next iteration (divide by 10)
        carry = Math.floor(digitSum / 10);
        
        // Create new node with the ones digit
        const newNode = new ListNode(digitSum % 10);
        currentTail.next = newNode;
        currentTail = newNode;
    }
    
    // Return the actual result (skip the dummy head node)
    return dummyHead.next;
};
