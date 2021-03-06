
// ? Sort a LL of 0's, 1's and 2's


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
    Node *head = NULL;
    Node *tail = NULL;

public:
    void create(vector<int>);
    void sort();
    void display();
};
int main()
{
    Linkedlist a;
    vector<int> arr ={};
    a.create(arr);
    a.sort();
    a.display();
    return 0;
}

void Linkedlist ::create(vector<int> arr)
{
    head = new Node;
    Node *temp;
    head->data = arr[0];
    tail = head;
    int i = 1;
    while (i < arr.size())
    {
        temp = new Node;
        temp->data = arr[i];
        tail->next = temp;
        tail = temp;
        i++;
    }
}

void Linkedlist ::sort()
{
    Node *one = NULL;
    Node *two = NULL;
    Node *zero = NULL;
    Node *temp = head;
    Node *first;
    Node *tail = NULL;
    Node *curr;
    Node *zero_head= NULL;
    Node *one_head= NULL;
    Node *two_head= NULL;
    int j = 0, k = 0, l = 0;
    while (temp)
    {
        // * 0,2,0,2,0,2,0,2,0,2,0,2
        if (temp->data == 0)
        {
            if (!zero || zero->next == temp)
            {
                zero = temp;
                if (j != 1)
                {
                    zero_head = zero;
                    j++;
                }
            }
            else
            {
                tail->next = temp->next;
                curr = zero->next;
                zero->next = temp;
                temp->next = curr;
                two = temp;
                temp = tail;
            }
        }
        // * 0,2,0,2,0,2,0,2,0,2,0,2
        else if (temp->data == 1)
        {
            if (!one || one->next == temp)
            {
                one = temp;
                if (k != 1)
                {
                    one_head = one;
                    k++;
                }
            }
            else
            {
                tail->next = temp->next;
                curr = one->next;
                one->next = temp;
                temp->next = curr;
                one = temp;
                temp = tail;
            }
        }
        else
        // * 0,2,0,2,0,2,0,2,0,2,0,2
        {
            if (!two || two->next == temp)
            {
                two = temp;
                if (l != 1)
                {
                    two_head = two;
                    l++;
                }
            }
            else
            {
                tail->next = temp->next;
                curr = two->next;
                two->next = temp;
                temp->next = curr;
                two = temp;
                temp = tail;
            }
        }
        tail = temp;
        temp = temp->next;
    }
    if(zero_head)
    {
        this->head=zero_head;
        first=zero;
        if(one_head)
        {
            zero->next=one_head;
            first=one;
        }
        if(two_head)
        {
            first->next=two_head;
            first=two;
        }
        first->next=NULL;
        this->tail=first;
    }
    else if(one_head)
    {
        this->head=one_head;
        first=one;
        if(two_head)
        {
            one->next=two_head;
            first=two;
        }
        first->next=NULL;
        this->tail=first;
    }
    else
    {
        this->head=two_head;
        this->tail=two;
    }
}

void Linkedlist ::display()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}