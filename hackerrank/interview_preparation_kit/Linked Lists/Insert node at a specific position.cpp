#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout)
{
    while (node)
    {
        cout << node->data << endl;
        fout << node->data;

        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *llist, int data, int position)
{
    static int i = 0;
    static SinglyLinkedListNode *head = llist;
    if (i == position - 1)
    {
        SinglyLinkedListNode *node_ptr = new SinglyLinkedListNode(data);
        node_ptr->next = llist->next;
        llist->next = node_ptr;
        return head;
    }
    else
    {
        i++;
        return insertNodeAtPosition(llist->next, data, position);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count = 3;
    vector<int> node_data = {16, 13, 7};
    for (int i = 0; i < llist_count; i++)
    {
        int llist_item = node_data[i];
        llist->insert_node(llist_item);
    }

    int data = 1;
    int position = 2;

    SinglyLinkedListNode *llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ", fout);
    fout << "\n";

    free_singly_linked_list(llist_head);

    fout.close();

    return 0;
}
