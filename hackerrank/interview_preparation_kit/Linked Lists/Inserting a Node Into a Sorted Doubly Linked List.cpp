#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode
{
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;

    DoublyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;

    DoublyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        DoublyLinkedListNode *node = new DoublyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
            node->prev = this->tail;
        }

        this->tail = node;
    }
};

void print_doubly_linked_list(DoublyLinkedListNode *node, string sep, ofstream &fout)
{
    while (node)
    {
        fout << node->data;
        cout << node->data;
        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode *node)
{
    while (node)
    {
        DoublyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *llist, int data)
{

    if (llist == nullptr)
    {
        DoublyLinkedListNode *new_node = new DoublyLinkedListNode(data);
        return new_node;
    }
    else if (data <= llist->data)
    {
        DoublyLinkedListNode *new_node = new DoublyLinkedListNode(data);
        new_node->next = llist;
        return new_node;
    }
    else if (llist->next == nullptr)
    {
        DoublyLinkedListNode *new_node = new DoublyLinkedListNode(data);
        new_node->next = llist->next;
        llist->next = new_node;
        new_node->prev = llist;
        return llist;
    }
    else if (data >= llist->data && data <= llist->next->data)
    {
        DoublyLinkedListNode *new_node = new DoublyLinkedListNode(data);
        new_node->next = llist->next;
        llist->next = new_node;
        new_node->prev = llist;
        return llist;
    }
    else
        return sortedInsert(llist->next, data);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;

    DoublyLinkedList *llist = new DoublyLinkedList();

    vector<int> arr = {2,
                       3,
                       4,
                       10};
    for (auto x : arr)
    {
        llist->insert_node(x);
    }

    int data = 11;

    DoublyLinkedListNode *llist1 = sortedInsert(llist->head, data);

    print_doubly_linked_list(llist1, " ", fout);
    fout << "\n";

    free_doubly_linked_list(llist1);

    fout.close();

    return 0;
}