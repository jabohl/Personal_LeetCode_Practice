/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

/**
 * Adds two numbers represented as linked lists in reverse order.
 * 
 * For example:
 *   342 + 465 = 807
 *   Represented as: 2->4->3 + 5->6->4 = 7->0->8
 * 
 * Time Complexity: O(max(len(l1), len(l2)))
 * Space Complexity: O(max(len(l1), len(l2))) for the result list
 * 
 * @param l1 Pointer to the first linked list (represents first number in reverse)
 * @param l2 Pointer to the second linked list (represents second number in reverse)
 * @return Pointer to the head of the result linked list, or NULL on allocation failure
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    /* Initialize carry for digit addition */
    int carry = 0;
    
    /* Create a dummy head node to simplify list construction */
    /* This dummy node will be removed before returning the result */
    struct ListNode dummyHead;
    dummyHead.val = 0;
    dummyHead.next = NULL;
    
    /* Maintain a pointer to the last node in the result list */
    /* Initially points to dummy head; will be updated as we add nodes */
    struct ListNode *currentTail = &dummyHead;
    
    /* Continue processing while there are digits in either list or a carry remains */
    while (l1 != NULL || l2 != NULL || carry != 0) {
        /* Start with the carry from the previous digit addition */
        int digitSum = carry;
        
        /* Add the digit from the first list if it exists */
        if (l1 != NULL) {
            digitSum += l1->val;
            l1 = l1->next;  /* Move to next node in first list */
        }
        
        /* Add the digit from the second list if it exists */
        if (l2 != NULL) {
            digitSum += l2->val;
            l2 = l2->next;  /* Move to next node in second list */
        }
        
        /* Calculate carry for the next iteration (divide by 10) */
        carry = digitSum / 10;
        
        /* Allocate memory for the new result node */
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        
        /* Check for memory allocation failure */
        if (newNode == NULL) {
            return NULL;  /* Return NULL if memory allocation fails */
        }
        
        /* Store the ones digit (remainder when divided by 10) in the new node */
        newNode->val = digitSum % 10;
        newNode->next = NULL;
        
        /* Link the new node to the result list */
        currentTail->next = newNode;
        
        /* Update the tail pointer to the newly added node */
        currentTail = newNode;
    }
    
    /* Return the actual result (skip the dummy head node) */
    return dummyHead.next;
}
