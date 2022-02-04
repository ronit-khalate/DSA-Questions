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
    void reverse_list(Node *, int);
    void display();
};
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Linkedlist a;
    a.create(arr, 10);
    a.reverse_list(a.head, 1);
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
    cout << "\n";
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

void Linkedlist ::reverse_list(Node *h, int key)
{
    /*
        ! first half
        ? key=3
        ? 1->2->3->4->5->6->7->8->9->10
        * a=NULL,b=NULL ,c = h;
        *a=b
        *b=c
        *c=c->next
        *b->next=a
        ! loop 1
        * a=b (a=null)
        * b=c (b=1)
        * c=c->next (c=2)
        * b->next=a (null<-1)
        ! loop 2
        * a=b (a=1)
        * b=c (b=2)
        * c=c->next (c=3)
        * b->next=a (null<-1<-2)
        ! loop 3
        * a=b (a=2)
        * b=c (b=3)
        * c=c->next (c=4)
        * b->next=a (null<-1<-2<-3<-4)
        
        * first reversed list ( key =4) 4->3->2->1->NULL
        * NOW b=4 and b is going to be head of our list so we have to assigne our this->head=b

    
        !second half
        *c=5
        *a=b
        *b=c
        *c=c->next
        *b->next=a
        ! loop 1
        * a=b (a=null)
        * b=c (b=5)
        * c=c->next (c=6)
        * b->next=a (null<-5  6->7->8->9->10)
        ! loop 2
        * a=b (a=5)
        * b=c (b=6)
        * c=c->next (c=7)
        * b->next=a (null<-5<-6  7->8->9->10)
        ! loop 3
        * a=b (a=6)
        * b=c (b=7)
        * c=c->next (c=8)
        * b->next=a (null<-5<-6<-7   8->9->10 )
        ! loop 4
        * a=b (a=7)
        * b=c (b=8)
        * c=c->next (c=9)
        * b->next=a (null<-5<-6<-7<-8   9->10 )
        ! loop 5
        * a=b (a=8)
        * b=c (b=9)
        * c=c->next (c=10)
        * b->next=a (null<-5<-6<-7<-8<-9   10 )
        ! loop 6
        * a=b (a=9)
        * b=c (b=10)
        * c=c->next (c=null)
        * b->next=a (null<-5<-6<-7<-8<-9<-10    )
    
        * now we have reversed our second half list in this case from  5 to 10
        * now b =10 and b is head for this second half list
        * 
    */
    Node *a = NULL, *b = NULL, *c = h, *t, *tail_of_first_reversed_list = h;
    do
    {

        a = b;
        b = c;
        c = c->next;
        b->next = a;

    } while (b->data != key);
    this->head = b;
    a = NULL;
    b = NULL;
    Node*new_tail=c; // !current c is going to be tail of new reversed list's tail
                     // ! but we cant change this->tail at this point because second half list haven't reversed yet
                     // ! so we have to save current "c" so we can reassigne it to this->tail 
    while (c)
    {
        a = b;
        b = c;
        c = c->next;
        b->next = a;
    }

    tail_of_first_reversed_list->next = b;
    this->tail=new_tail; // * reassigned this->tail to new tail node
}