
// ? Check if Linked List is Palindrome
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
    void create(vector<int>);
    bool isPalindrome();
    Node *find_mid();
    Node *reverse(Node *);
};
int main()
{
    Linkedlist a;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    a.create(arr);
    cout << a.isPalindrome();

    return 0;
}

void Linkedlist ::create(vector<int> arr)
{
    Node *temp;
    if (!head)
    {
        head = new Node;
        head->data = arr[0];
        tail = head;
    }
    int i = 1;
    while (i < arr.size())
    {
        temp = new Node;
        temp->data = arr[i];
        tail->next = temp;
        tail = temp;
        temp = NULL;
        i++;
    }
}

bool Linkedlist ::isPalindrome()
{
    Node *mid = find_mid();
    mid->next = reverse(mid->next);
    Node *a = head, *b = mid->next;

    while (b)
    {
        if (a->data != b->data)
        {
            mid->next = reverse(mid->next);
            return false;
        }
        a = a->next;
        b = b->next;
    }
    mid->next = reverse(mid->next);
    return true;
}

Node *Linkedlist ::find_mid()
{
    Node *slow = head, *fast = head->next;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *Linkedlist ::reverse(Node *start)
{
    Node *a = NULL, *b = NULL, *c = start;

    while (c)
    {
        a = b;
        b = c;
        c = c->next;
        b->next = a;
    }

    return b;
}