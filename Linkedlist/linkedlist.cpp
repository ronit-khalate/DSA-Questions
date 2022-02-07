#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
};
class Lnode
{
    Node*last;
    public:
    Node*data;
    Lnode*next=NULL;

};
class Linkedlist
{
    Lnode*Lfirst=NULL,*Llast=NULL;
    public:
    void createLnode(int*);
    void create_int_list(int*,Node*);
};
void Linkedlist ::create(int *arr)
{
    if(Lfirst==NULL)
    {
        Lnode*t=new Lnode;
        Node*p=new Node;
        Lfirst=t;
        Llast=t;
        t->data=p;
        t->last=p;

        
    }
    else
    {
        Lnode*t=new Lnode;
        Node*p=new Node;
        Llast->next=t;
        Llast=t;
        Llast->data=p;
        Llast->last=p;

    }
}
int main()
{
   
   return 0;
}

void Linkedlist ::create_int_list(int arr[],Node*l)
{
    for
}