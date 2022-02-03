// Write a Program to reverse the Linked List. (Both Iterative and recursive)

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
    Node *reverse_list(Node *);
    void rec_reverse_list(Node *, Node *);
    void display();
};
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Linkedlist a;
    a.create(arr, 10);
    a.head = a.reverse_list(a.head);
    a.display();
    a.rec_reverse_list( NULL,a.head);
    a.display();

    return 0;
}
// Linkedlist functions

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

Node *Linkedlist ::reverse_list(Node *head)
{
    Node *a = NULL, *b = NULL, *c;
    c = head;
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
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<"\n";
}

void Linkedlist ::rec_reverse_list( Node *temp,Node *head)
{
    /*
        * this is recursive if condition going run until head becomes NULL
        *temp is tail pointer of head when head becomes NULL tail will be on last node of list
        *when head becomes NULL if condition  becomes false and else condition will execute
        *in else condtion we assgine this->head ( first pointer which pointes on first node) to the temp
        *temp  pointing on last node because we reversing the list we have to assigne this->head pointer to the 
        *last node of list 

        *after  execution of else condition flow of code gose to next part of recursive call
        *(at head->=temp) since the recursivem call didn't happend when head becomes NULL 
        * hence head==NULL dont have any activation record so after else condition excution gose
        *to head->next=temp of latest activation recorde which is when head== last node1->2->3->4 <--head
        * now at latest activation recored head=last node and temp=previous of head
        * so head->next =temp(previous of last node)
        * after that flow of code gose to previous activation recorde where head=second last node1->2->3<--head <-4
        * this happend at return time therefor 
        * 
        * 1->2->3->4<--head
        * 1->2->3<-- head<-4
        * 1->2 <--head <-3<-4
        * 1<--head<-2<-3<-4
        * <--head 1<-2<-3<-4
    */
    if (head)
    {
        rec_reverse_list(head,head->next);
        head->next = temp;
    }
    else
    {
        this->head=temp;
    }
}