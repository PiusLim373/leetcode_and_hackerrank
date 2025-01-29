var deleteDuplicates = function (head) {
    let sentinel = new ListNode(0, head);
    let pred = sentinel;
    while (head) {
        if (head.next && head.val === head.next.val) {
            while (head.next && head.val === head.next.val) { head = head.next; }
            pred.next = head.next;
        }
        else {
            pred = pred.next;
        }
        head = head.next;
    }
    return sentinel.next;
};