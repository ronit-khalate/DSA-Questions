// ?Remove Duplicates in a sorted Linked List.

#include<bits/stdc++.h>
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
    void find_dublicate();
    void display();
};
int main()
{
   Linkedlist a;
   vector<int>arr={2,2,4,5,6,7,7,8,8,9,10,11,11,12,13,13,14,15,15};
   a.create(arr);
   a.find_dublicate();
   a.display();
   return 0;
}

void Linkedlist ::create(vector<int>arr)
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

void Linkedlist ::find_dublicate()
{
    Node*tail=head,*temp=head->next;

    while (temp)
    {
        if(temp->data==tail->data)
        {
            tail->next=temp->next;
            delete temp;
            temp=tail->next;
        }
        else
        {
            tail=temp;
            temp=temp->next;
        }
    }
    
}

void Linkedlist ::display()
{
    Node*temp=head;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}