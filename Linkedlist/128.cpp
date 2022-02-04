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
    void create(int *, int, int);
    void find_loop();
    void find_starting_point();
    void display();
};
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Linkedlist a;
    a.create(arr, 10, 9);
    a.find_loop();
    a.find_starting_point();
    // a.display();

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
// * this function will create looped linked list at given node data
void Linkedlist ::create(int arr[], int n, int key)
{
    Node *loop_node, *temp;
    if (!head)
    {
        head = new Node;
        head->data = arr[0];
        tail = head;
        cout << "\n";
    }
    int i = 1;
    while (i < n)
    {

        temp = new Node;
        temp->data = arr[i];
        tail->next = temp;
        tail = temp;
        if (arr[i] == key)
        {
            loop_node = temp;
        }
        temp = NULL;
        i++;
    }
    tail->next = loop_node;
}

void Linkedlist ::find_loop()
{
    if(tail->next)
        cout<<"True";
    else
        cout<<"False";
    cout<<"\n";
}

void Linkedlist :: find_starting_point()
{
    Node*t=tail->next;
    if(tail->next)
        cout<<"Starting point of Loop is "<<t->data<<"\n";
}