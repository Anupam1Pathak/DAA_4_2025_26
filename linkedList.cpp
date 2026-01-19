#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data1)
    {
        data = data1;
        next = NULL;
    }

    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }
};

void print(node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Insert at head
node *insertAtHead(node *head, int val)
{
    node *temp = new node(val, head);
    return temp;
}

// Insert at tail
node *insertAtTail(node *head, int val)
{
    if (head == NULL)
    {
        node *temp = new node(val);
        return temp;
    }

    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new node(val);
    return head;
}

// Insert at position (1-based)
node *insertAtPosition(node *head, int val, int k)
{
    if (k == 1)
    {
        return insertAtHead(head, val);
    }

    node *temp = head;
    int count = 1;

    while (temp != NULL && count < k - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        cout << "Invalid position" << endl;
        return head;
    }

    node *newnode = new node(val, temp->next);
    temp->next = newnode;
    return head;
}

// Insert before given element
node *insertBeforeElement(node *head, int val, int el)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }

    if (head->data == el)
    {
        return insertAtHead(head, val);
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == el)
        {
            node *newnode = new node(val, temp->next);
            temp->next = newnode;
            return head;
        }
        temp = temp->next;
    }

    cout << "Element not found" << endl;
    return head;
}

// Delete head
node *deleteHead(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete tail
node *deleteTail(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    return head;
}

// Delete at position (1-based)
node *deleteAtPosition(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (k == 1)
    {
        return deleteHead(head);
    }

    node *temp = head;
    int count = 1;

    while (temp->next != NULL && count < k - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        cout << "Invalid position" << endl;
        return head;
    }

    node *del = temp->next;
    temp->next = del->next;
    delete del;
    return head;
}

// Delete by value
node *deleteByValue(node *head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->data == val)
    {
        return deleteHead(head);
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            node *del = temp->next;
            temp->next = del->next;
            delete del;
            return head;
        }
        temp = temp->next;
    }

    cout << "Value not found" << endl;
    return head;
}

int main()
{
    node *head = NULL; // empty linked list

    head = insertAtHead(head, 10);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    head = insertAtPosition(head, 15, 2);
    head = insertBeforeElement(head, 5, 10);

    print(head);

    head = deleteHead(head);
    head = deleteTail(head);
    head = deleteAtPosition(head, 2);
    head = deleteByValue(head, 20);

    print(head);

    return 0;
}
