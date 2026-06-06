#include <stdlib.h>


struct ListNode* addTwoNumbers(struct ListNode* firstNumberList, struct ListNode* secondNumberList) {
    int carry = 0;


    struct ListNode dummyHead;
    dummyHead.val = 0;
    dummyHead.next = NULL;


    struct ListNode *currentTail = &dummyHead;


    while (firstNumberList != NULL || secondNumberList != NULL || carry != 0) {
        int digitSum = carry;


        if (firstNumberList != NULL) {
            digitSum += firstNumberList->val;
            firstNumberList = firstNumberList->next;
        }


        if (secondNumberList != NULL) {
            digitSum += secondNumberList->val;
            secondNumberList = secondNumberList->next;
        }


        carry = digitSum / 10;


        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));


        if (newNode == NULL) {
            return NULL;
        }


        newNode->val = digitSum % 10;
        newNode->next = NULL;


        currentTail->next = newNode;


        currentTail = newNode;
    }


    return dummyHead.next;
}
