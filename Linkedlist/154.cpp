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
    vector<int> arr = {1, 2, 2, 0, 0, 2, 1, 1, 0, 1, 2, 2, 2, 1, 0, 1, 1, 2, 2, 2};
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
    Node *first = head;
    Node *tail = NULL;
    Node *curr;
    Node *zero_head;
    Node *one_head;
    Node *two_head;
    int j = 0, k = 0, l = 0;
    while (temp)
    {
        // * 1,2,2,0,0,2,1,1,0
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
        // * 1,2,2,0,0,2,1,1,0
        else if (temp->data == 1)
        {
            if (!one || one->next == temp)
            {
                one = temp;
                if (k = 1)
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
        // * 1,2,2,0,0,2,1,1,0
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
    zero->next = one_head;
    one->next = two_head;
    this->tail = two;
    this->head = zero_head;
    two->next = NULL;
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