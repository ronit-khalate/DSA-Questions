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
    Node *head = NULL, *tail = NULL;
    int number_of_nodes;

public:
    void create(vector<int>);
    Node *reverse();
    void display();
    void add1();
};
int main()
{
    vector<int> arr = {1,9,9,4,9};
    Linkedlist a;
    a.create(arr);
    a.display();
    cout<<"\n";
    a.add1();
    a.display();
    return 0;
}
void Linkedlist ::create(vector<int> arr)
{
    Node *temp;
    if (!head)
    {
        head = new Node;
        head->data = arr[0];
        tail = head;
    }
    int i = 1;
    while (i < arr.size())
    {
        temp = new Node;
        temp->data = arr[i];
        tail->next = temp;
        tail = temp;
        temp = NULL;
        i++;
    }
}

void Linkedlist ::add1()
{

    // ? 9,9,9,1
    int carry = 0;

    this->head = reverse();
    Node *temp = head;
    if (temp->data == 9)
    {
        temp->data = 0;
        carry = 1;
    }
    else
    {
        temp->data++;
    }
    temp = temp->next;

    while (temp)
    {
       
    }
    this->head = reverse();
}

Node *Linkedlist ::reverse()
{
    Node *a = NULL, *b = NULL, *c = head;

    while (c)
    {
        a = b;
        b = c;
        c = c->next;
        b->next = a;
    }

    return b;
}

void Linkedlist ::display()
{
    Node*temp=head;
    while (temp)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    
}