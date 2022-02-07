
// ? Intersection Point of two Linked Lists.


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

public:
    Node *head = NULL;
    Node *tail = NULL;
    void create(int *, int);
    friend void create_insection(Linkedlist , Linkedlist , int);
    friend void find_intersection(Linkedlist,Linkedlist);
};
int main()
{
    Linkedlist a, b;
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    a.create(arr1, 10);
    b.create(arr2, 10);
    create_insection(a, b, 7);
    find_intersection(a,b);
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
        tail = temp;
        temp = NULL;
        i++;
    }
}

void create_insection(Linkedlist main, Linkedlist sec, int point)
{
    /**
     * *This function creates intersection of two linkedlist
     * * parameter point is which node of main linkedlist is going to
     * * be intersection for two linkedlist
     * ! Example point=5;
     *          * then 5th node of main list is gonna be intersection
     *          * and sec list's tail-> is 5th node of main node
     *          * then both main and sec list will have same tail pointer
     *          * in this case is gonna be main list's tail(10)
     */
    int i = 1;
    Node *temp = main.head;
    while (i < point)
    {
        temp = temp->next;
        i++;
    }
    /**
     * * ^Above function bring temp on point'th node of main function
     */

    sec.tail->next = temp; // ! link second list's tail to the temp (temp is intersection point)
    sec.tail=main.tail; // ! Ressing second list's tail to new tail which is main's tail
}

void find_intersection(Linkedlist a,Linkedlist b)
{
    Node*first=a.head;
    Node*second=b.head;
    set<Node*> s;
    while (first)
    {
        s.insert(first);
        first=first->next;
    }
    /**
     * * ^ above loop will insert all Node address to the set
     */

    while (second)
    {
        auto i=s.insert(second);
        if(!i.second)
        {
            break;
        }
        second=second->next;
    }
     /**
     * * ^ above loop will insert all Node address in the set until the intersection node
     * * because intersection node is alread present in set cause we inserted all node address
     * * main linkedlist
     */

    cout<<"Intersection present  at : "<<second->data<<"\n";
    
    
    
}