
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* firstNumberList, ListNode* secondNumberList) {
        int carry = 0;


        ListNode* dummyHead = new ListNode(0);
        ListNode* currentTail = dummyHead;


        while (firstNumberList != nullptr || secondNumberList != nullptr || carry != 0) {
            int digitSum = carry;


            if (firstNumberList != nullptr) {
                digitSum += firstNumberList->val;
                firstNumberList = firstNumberList->next;
            }


            if (secondNumberList != nullptr) {
                digitSum += secondNumberList->val;
                secondNumberList = secondNumberList->next;
            }


            carry = digitSum / 10;


            ListNode* newNode = new ListNode(digitSum % 10);
            currentTail->next = newNode;
            currentTail = newNode;
        }


        return dummyHead->next;
    }
};
