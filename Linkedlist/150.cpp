#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*next=NULL;
    Node*previous=NULL;
};

class Linkedlist
{
    Node*head=NULL;
    Node*tail=NULL;
    public:
     void create(int *, int);
};
int main()
{
   
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