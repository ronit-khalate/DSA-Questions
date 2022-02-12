
//? Find pairs with given sum in doubly linked list
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
    void find_pair();
    Node *getTail();
};
int main()
{
    Dlinkedlist a;
    vector<int> arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    a.create(arr);
    a.find_pair();

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
Node *Dlinkedlist ::getTail()
{
    Node *temp = head;
    while (temp->next)
    {

        temp = temp->next;
    }
    return temp;
}
void Dlinkedlist ::find_pair()
{
    int sum;
    cout << "Enter the sum : ";
    cin >> sum;

    Node*tail=getTail();
    Node*head=this->head;

    while (head->data<tail->data)
    {
        if(head->data+tail->data==sum)
        {
            cout<<"( "<<head->data<<" , "<<tail->data<<" )"<<" ";
            head=head->next;
            tail=tail->previous;
        }
        else if(head->data+tail->data>sum)
        {
            tail=tail->previous;
        }
        else
        {
            head=head->next;
        }
    }

    
}