#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
};
class Dlinkedlist
{
    Node *head = NULL;
    Node *tail = NULL;

public:
    void create(int *, int);
    void quicksort(Node *, Node *);
    Node *partition(Node *, Node *)
};
int main()
{

    return 0;
}

void Dlinkedlist ::create(int arr[], int n)
{
    head = new Node;
    head->data = arr[0];
    tail = head;
    int i = 1;
    Node *temp;
    while (i < n)
    {
        temp = new Node;
        temp->data = arr[i];
        tail->next = temp;
        tail = temp;
        temp = NULL;
    }
}

void Dlinkedlist ::quicksort(Node*i,Node)
{
    Node *t = partition(head, tail);
}

Node *Dlinkedlist ::partition()
{
    //* 1 -> 6 -> 4 -> 3 -> 0 -> 9 -> 11
    Node *pivot = head;
    Node *tail_i = NULL;
    Node *tail_j = NULL;
    Node *i = head;
    Node *j = head;

    while (j != pivot)
    {
        while (i->data <= pivot->data)
        {
            tail_i = i;
            i = i->next;
        }

        while (j->data > pivot->data)
        {
            tail_j = j;
            j = j->next;
        }

        if (j != pivot)
        {
            tail_i->next = j;
            tail_j->next = i;
        }
    }
    tail_i->next = j;
    tail_j->next = i;
    return j;
}