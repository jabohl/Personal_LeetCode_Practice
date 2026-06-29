#include <stdlib.h>


struct ListNode* addTwoNumbers(struct ListNode* firstNumberList, struct ListNode* secondNumberList) {
    int carryValue = 0;


    struct ListNode dummyHeadNode;
    dummyHeadNode.val = 0;
    dummyHeadNode.next = NULL;


    struct ListNode *currentTailNode = &dummyHeadNode;


    while (firstNumberList != NULL || secondNumberList != NULL || carryValue != 0) {
        int currentDigitSum = carryValue;


        if (firstNumberList != NULL) {
            currentDigitSum += firstNumberList->val;
            firstNumberList = firstNumberList->next;
        }


        if (secondNumberList != NULL) {
            currentDigitSum += secondNumberList->val;
            secondNumberList = secondNumberList->next;
        }


        carryValue = currentDigitSum / 10;


        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));


        if (newNode == NULL) {
            return NULL;
        }


        newNode->val = currentDigitSum % 10;
        newNode->next = NULL;


        currentTailNode->next = newNode;


        currentTailNode = newNode;
    }


    return dummyHeadNode.next;
}
