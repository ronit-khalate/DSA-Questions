#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *previous = NULL;
    Node *next = NULL;
};
class Linkedlist
{
    Node *head = NULL, *tail = NULL;

public:
    void create(int *, int);
    void reverse();
    void display();
};
int main()
{
    Linkedlist a;
    int arr[10] = {5, 8, 2, 12, 9, 2, 12, 56, 8, 9};
    a.create(arr, 10);
    a.display();
    a.reverse();
    a.display();
    return 0;
}

void Linkedlist ::create(int arr[], int n)
{
    Node *temp;
    head = new Node;
    head->data = arr[0];
    tail = head;
    int i = 1;
    while (i < n)
    {
        temp = new Node;
        temp->data = arr[i];
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
        temp = NULL;
        i++;
    }
    head->previous = tail;
    tail->next=head;
}

void Linkedlist ::reverse()
{

    // * {5, 8, 2, 12, 9, 2, 12, 56, 8, 9};

    Node *temp = head;
    Node*t=NULL;
    do
    {
        /**
         * *we swaping next and previous of all node
         * * then we swap head to new head in this case is tail 
         * * and tail to new tail which head
         * 
         */
        t = temp->next;
        temp->next = temp->previous;
        temp->previous = t;
        temp=t;
        t=NULL;

    } while (temp != head);

    t=head;
    head=tail;
    tail=t;
   
}

void Linkedlist :: display()
{
    Node*temp=this->head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);
    cout<<"\n";
    
    
}