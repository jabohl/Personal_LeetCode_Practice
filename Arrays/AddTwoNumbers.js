var addTwoNumbers = function(firstNumberList, secondNumberList) {
    let carry = 0;


    const dummyHead = new ListNode(0);
    let currentTail = dummyHead;


    while (firstNumberList !== null || secondNumberList !== null || carry !== 0) {
        let digitSum = carry;


        if (firstNumberList !== null) {
            digitSum += firstNumberList.val;
            firstNumberList = firstNumberList.next;
        }


        if (secondNumberList !== null) {
            digitSum += secondNumberList.val;
            secondNumberList = secondNumberList.next;
        }


        carry = Math.floor(digitSum / 10);


        const newNode = new ListNode(digitSum % 10);
        currentTail.next = newNode;
        currentTail = newNode;
    }


    return dummyHead.next;
};
