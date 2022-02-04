

// ? Remove duplicates from an unsorted linked list
/*
 *Given an unsorted linked list of N nodes. The task is to remove duplicate
 *elements from this unsorted Linked List. When a value appears in multiple nodes,
 *the node which appeared first should be kept, all others duplicates are to be removed.
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
    Node *head = NULL, *tail = NULL;
    int number_of_nodes;

public:
    void create(int *, int);
    void find_dublicate();
    void display();
};
int main()
{
    Linkedlist a;
    int arr[10] = {5, 8, 2, 12, 9, 2, 12, 56, 8, 9};
    a.create(arr, 10);
    a.display();
    a.find_dublicate();
    a.display();

    return 0;
}

void Linkedlist ::create(int arr[], int n)
{
    Node *temp;
    number_of_nodes = n;
    if (!head)
    {
        head = new Node;
        head->data = arr[0];
        tail = head;
    }
    int i = 1;
    while (i < n)
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
    // * we are using unorded set all elements in set are unique
    Node *temp = head, *tail = NULL;
    unordered_set<int> s;
    /**
     * * set are collection of unique data we cant insert data which is alredy present in set
     * * we find if element which we were tring to insert is alredy present of not
     * ? How
     * 
     * 
     */
    while (temp)
    {
        auto i=s.insert(temp->data);
        /**
          *!insert function of unorderd_set returns a pair having two value 
           *!first is iterator pointer where element is inserted or if element is  already
           *! present then the pointer to that element
           *! second is bool value true:: if insertes || false :: not inserted
           * ! return type is auto ex : auto i = s.insert(
           *? How to access first and second value
                ** i.first and i.second
            *! if i.second == true then element is unique else element is alredy present
            *! and not inserted
        */
        
        if(i.second) // * checks if element is inserted or not 
        {
          

            tail=temp;
            temp=temp->next;
        }
        else //* temp->data is alredy exits in list and need to delete
        {
            
            tail->next=temp->next;
            delete temp;
            temp=tail->next;
        }
    }
    
    
}

void Linkedlist :: display()
{
    Node*temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}