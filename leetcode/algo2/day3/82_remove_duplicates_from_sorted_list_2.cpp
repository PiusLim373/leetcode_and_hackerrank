// failed solution, failed cases= [1,1,1], [1,1,5,5]
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *slow = head;
    ListNode *fast = head->next;

    if (slow->val == fast->val)
    {
        if (fast->next == nullptr)
            return nullptr;
        int curr = slow->val;
        while (fast->val == curr)
            fast = fast->next;
        slow = fast;
        fast = fast->next;

        head = slow;
        if (head->next == nullptr)
            return head;
    }
    cout << "updated slow" << slow->val << endl;
    cout << "updated fast" << fast->val << endl;
    int counter = 1;
    while (fast != nullptr)
    {
        int curr = fast->val;
        int next = 0;
        if (fast->next == nullptr)
        {
            if (counter > 1)
            {
                slow->next = nullptr;
                break;
            }
            else
                next = 999;
        }
        else
            next = fast->next->val;

        cout << curr << " " << next << " " << counter << endl;

        if (next == curr)
        {
            counter++;
        }
        else if (next != curr && counter > 1)
        {
            counter = 1;
        }
        else
        {
            cout << "else " << curr << " " << next << " " << counter << endl;
            counter = 1;
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }
    return head;
}

// correct ans
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *sentinel = new ListNode(0, head);
    ListNode *pred = sentinel;
    while (head != nullptr)
    {
        if (head->next != nullptr && head->val == head->next->val)
        {
            while (head->next != nullptr && head->val == head->next->val)
                head = head->next;
            pred->next = head->next;
        }
        else
        {
            pred = pred->next;
        }
        head = head->next;
    }
    return sentinel->next;
}