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
    void reverse_list(int);
    void display();
    vector<pair<Node *, Node *>> &group(int, Node *);
};
int main()
{
    int arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Linkedlist a;
    a.create(arr, 12);
    a.reverse_list(4);
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

vector<pair<Node *, Node *>> &Linkedlist ::group(int key, Node *head)
{
    // * 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12
    /**
     * * This function will create groups of node depending on key  it will save address of
     * * starting node and ending node of each group in pair<Node*,Node*> and then it'll 
     * * push back that pair in vector 
     * ! Now we have vector containing address of Nodes Of each group's Starting and ending Nodes
     *
     */
    static vector<pair<Node *, Node *>> vec; // * vector of pair to save add of nodes
    int i = 1;
    Node *first = NULL;
    Node *second = NULL;
    Node *tail = NULL; // ! tail pointer of head

    // ?Use of Tail Pointer?
    /*
            * for last group we want save last node as ending node but the trasversal
            * will continue until head becomes NULL as you can we are saving head in second
            * but for last during last group head becomes NULL So thats why tail pointer is use 
            * for last group's ending Node
        */

    // * 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12
    while (head)
    {
        first = head;

        for (i = 1; i < key && head->next; i++) // TODO :: change contion head to head->next
        {
            tail = head;
            head = head->next;
        }

        second = head;

        vec.push_back(make_pair(first, second)); // ! creating pair and pushing back in vector

        tail = head;
        head = head->next; //! assining head to the starting node of next group
    }

    return vec;
}

void Linkedlist ::reverse_list(int key)
{
    vector<pair<Node *, Node *>> v = group(key, head);
    int i = 0;
    Node *h, *t;
    while (i < v.size())
    {
        /**
         * ! this loop wil revers all links of each group of Nodes
         * ! ex:- key=4 therefor 1->2->3->4 will become 1<-2<-3<-4
         * !                     5->6->7->8 will become 5<-6<-7<-8
         * !                     9->10->11->12 will become 9<-10<-11<-12
         */
        h = v[i].first;  // * head node of i th group
        t = v[i].second; // * tail node of i th group

        Node *a = NULL;
        Node *b = NULL;
        Node *c = h;
        // * Node * a *b,*c are pointer to reverse linkes
        while (b != t)
        {
            // ! iterative linkedlist reverse method
            a = b;
            b = c;
            c = c->next;
            b->next = a;
        }
        i++;
    }

    int k = 0;
    Node *j = NULL;
    while (k < v.size())
    {
        /**
         * * this loop will join the links of k th group's starting node
         * * to k+1 th group's ending node
         * ! Example :- now we have reversed groups
         * !            1<-2<-3<-4
         * !            5<-6<-7<-8
         * !            9<-10<-11<-12
         * 
         * * so this loop will join 
         * *        1->next to 8
         * *        5->next to 12
         * *        9->next to NULL
         * 
         * * at the end we reassing this->head to 4
         */
        if (j)
        {

            j->next = v[k].second;
        }
        j = v[k].first;
        k++;
    }

    head = v[0].second; // * reassiging this->head to first group's ending node (which is now head node)
}