#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
    Node *previous = NULL;
};
class Dlinkedlist
{
    Node *head = NULL;

public:
    void create(vector<int>);
    void sort_k(int);
    queue<Node*>add_to_queue(Node*);
};
int main()
{
    Dlinkedlist b;
    vector<int> arr ={3,6,2,12,56,8};
    b.create(arr);
    b.sort_k(2);

    return 0;
}
void Dlinkedlist ::create(vector<int> arr)
{
    Node *tail, *temp;
    int i = 1;
    if (!head)
    {
        head = new Node;
        head->data = arr[0];
        tail = head;
    }

    while (i < arr.size())
    {
        temp = new Node;
        temp->data = arr[i];
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
        i++;
    }
}

void Dlinkedlist ::sort_k(int k)
{


    Node *temp = head;
    for (int i = 0; i < k + 1; i++)
    {
        q.push(temp);
        temp = temp->next;
    }

    Node *a = q.top();
    q.pop();

    while (temp)
    {
        q.push(temp);
        temp=temp->next;
        a->next=q.top();
        a=q.top();
        q.pop();


    }
}

