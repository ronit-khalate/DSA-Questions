/*
    ? Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function)
    ? in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should
    ? be considered as a group and must be reversed (See Example 2 for clarification). ?
      /
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
};
class Linkedlist
{

    Node *tail = NULL;

public:
    Node *head = NULL;
    void create(int *, int);
    void reverse_list(int);
    void display();
    vector<pair<Node *, Node *>> &group(int, Node *);
};
int main()
{
    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Linkedlist a;
    a.create(arr, 12);
    a.reverse_list(4);
    // a.group(4, a.head);
    a.display();

    return 0;
}

void Linkedlist ::display()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void Linkedlist ::create(int arr[], int n)
{
    if (!head)
    {
        head = new Node;
        cout << "Enter the data : ";
        head->data = arr[0];
        tail = head;
        cout << "\n";
    }
    int i = 1;
    while (i < n)
    {

        Node *temp = new Node;
        temp->data = arr[i];
        tail->next = temp;
        tail = temp;
        i++;
    }
}

vector<pair<Node *, Node *>> &Linkedlist ::group(int key, Node *head)
{
    // * 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12
    static vector<pair<Node *, Node *>> vec;
    int i = 1;
    Node *first = NULL;
    Node *second = NULL;
    Node *tail = NULL;

    while (head)
    {
        first = head;

        for (i = 1; i < key && head; i++)
        {
            tail = head;
            head = head->next;
        }
        if (head)
        {

            second = head;
        }
        else
        {
            second = tail;
        }
        vec.push_back(make_pair(first, second));
        if (head)
        {
            tail = head;
            head = head->next;
        }
    }

    return vec;
}

void Linkedlist ::reverse_list(int key)
{
    vector<pair<Node *, Node *>> v = group(key, head);
    int i = 0;
    Node *h, *t;
    while (i < v.size())
    {
        h = v[i].first;
        t = v[i].second;
        Node *a = NULL;
        Node *b = NULL;
        Node *c = h;
        while (b != t)
        {
            a = b;
            b = c;
            c = c->next;
            b->next = a;
        }
        i++;
    }

    int k = 0;
    Node *j = NULL;
    while (k < v.size())
    {
        if (j)
        {

            j->next = v[k].second;
        }
        j = v[k].first;
        k++;
    }

    head = v[0].second;
}