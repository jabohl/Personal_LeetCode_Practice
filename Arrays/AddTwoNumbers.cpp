/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
 * };
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
 * @param firstNumberList Pointer to the first linked list (represents first number in reverse)
 * @param secondNumberList Pointer to the second linked list (represents second number in reverse)
 * @return Pointer to the head of the result linked list
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* firstNumberList, ListNode* secondNumberList) {
        // Initialize carry for digit addition
        int carry = 0;
        
        // Create a dummy head node to simplify list construction
        ListNode* dummyHead = new ListNode(0);
        ListNode* currentTail = dummyHead;
        
        // Continue processing while there are digits in either list or a carry remains
        while (firstNumberList != nullptr || secondNumberList != nullptr || carry != 0) {
            // Start with the carry from the previous digit addition
            int digitSum = carry;
            
            // Add the digit from the first list if it exists
            if (firstNumberList != nullptr) {
                digitSum += firstNumberList->val;
                firstNumberList = firstNumberList->next;
            }
            
            // Add the digit from the second list if it exists
            if (secondNumberList != nullptr) {
                digitSum += secondNumberList->val;
                secondNumberList = secondNumberList->next;
            }
            
            // Calculate carry for the next iteration (divide by 10)
            carry = digitSum / 10;
            
            // Create new node with the ones digit
            ListNode* newNode = new ListNode(digitSum % 10);
            currentTail->next = newNode;
            currentTail = newNode;
        }
        
        // Return the actual result (skip the dummy head node)
        return dummyHead->next;
    }
};
