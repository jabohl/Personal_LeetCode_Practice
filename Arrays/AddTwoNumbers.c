#include <stdlib.h>


struct ListNode* addTwoNumbers(struct ListNode* firstOfOurNumberLists, struct ListNode* secondOfOurNumberLists) {
    int carryValueForNeededCarriesOfSumsOfListValues = 0;


    struct ListNode dummyHeadNodeForKeepingTrackOfHeadNode;
    dummyHeadNodeForKeepingTrackOfHeadNode.val = 0;
    dummyHeadNodeForKeepingTrackOfHeadNode.next = NULL;


    struct ListNode *currentTailNode = &dummyHeadNodeForKeepingTrackOfHeadNode;


    while (firstOfOurNumberLists != NULL || secondOfOurNumberLists != NULL || carryValueForNeededPositionsInList != 0) {
        int currentDigitSumOfOurSurrentListValueBeingSummed = carryValueForNeededCarriesOfSumsOfListValues;


        if (firstOfOurNumberLists != NULL) {
            currentDigitSumOfOurSurrentListValueBeingSummed += firstOfOurNumberLists->val;
            firstOfOurNumberLists = firstOfOurNumberLists->next;
        }


        if (secondOfOurNumberLists != NULL) {
            currentDigitSumOfOurSurrentListValueBeingSummed += secondOfOurNumberLists->val;
            secondOfOurNumberLists = secondOfOurNumberLists->next;
        }


        carryValueForNeededCarriesOfSumsOfListValues = currentDigitSumOfOurSurrentListValueBeingSummed / 10;


        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));


        if (newNode == NULL) {
            return NULL;
        }


        newNode->val = currentDigitSumOfOurSurrentListValueBeingSummed % 10;
        newNode->next = NULL;


        currentTailNode->next = newNode;


        currentTailNode = newNode;
    }


    return dummyHeadNode.next;
}
