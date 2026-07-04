#include <stdlib.h>


struct ListNode* addTwoNumbers(struct ListNode* firstOfOurLists, struct ListNode* secondOfOurLists) {
    int carryForAddedValues = 0;


    struct ListNode nodeToKeepOrigin;
    nodeToKeepOrigin.val = 0;
    nodeToKeepOrigin.next = NULL;


    struct ListNode *currentTailNode = &nodeToKeepOrigin;


    while (firstOfOurLists != NULL || secondOfOurLists != NULL || carryForAddedValues != 0) {
        int sumOfNodeValues = carryForAddedValues;


        if (firstOfOurLists != NULL) {
            sumOfNodeValues += firstOfOurLists->val;
            firstOfOurLists = firstOfOurLists->next;
        }


        if (secondOfOurLists != NULL) {
            sumOfNodeValues += secondOfOurLists->val;
            secondOfOurLists = secondOfOurLists->next;
        }


        carryForAddedValues = sumOfNodeValues / 10;


        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));


        if (newNode == NULL) {
            return NULL;
        }


        newNode->val = sumOfNodeValues % 10;
        newNode->next = NULL;


        currentTailNode->next = newNode;


        currentTailNode = newNode;
    }


    return dummyHeadNode.next;
}
