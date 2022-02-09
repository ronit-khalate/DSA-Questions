#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
    Node *bottom = NULL;
};

class Linkedlist
{

public:
    Node *head = NULL;
    void create(vector<int>);
    void create_b(Node *);
    void fatten_list(Node *);
    pair<Node *, Node *> find_limit(Node *);
    Node *find_b_tail(Node *, Node *);
    Node *covert_b_list(Node *, Node *);
    void display();
};

int main()
{
    Linkedlist a;
    vector<int> arr = {5, 10, 19, 28};
    a.create(arr);
    a.fatten_list(a.head);
    a.display();

    return 0;
}

void Linkedlist ::create(vector<int> v)
{
    Node *tail, *temp;
    head = new Node;
    head->data = v[0];
    tail = head;
    create_b(tail);

    int i = 1;
    while (i < v.size())
    {
        temp = new Node;
        temp->data = v[i];
        create_b(temp);
        tail->next = temp;
        tail = temp;
        i++;
    }
}
void Linkedlist ::create_b(Node *temp)
{
    vector<int> s;
    Node *tail = temp, *head;
    cout << "Enter value greater that " << temp->data << "\n";
    cout << "Enter -1 To stop "
         << "\n";

    int x, z = 0;
    while (true)
    {
        cin >> x;
        if (x < temp->data || x == -1)
        {
            if (x ==-1)
            {
                break;
            }
            else
            {
                cout << "Enter data greater than " << temp->data << "\n";
            }
        }
        else
        {
            s.push_back(x);
        }
    }
    sort(s.begin(), s.end()); // *sorting data for bottom list
    for (int i = 0; i < s.size(); i++)
    {
        /* code */

        Node *c = new Node;
        c->data = s[i];
        head = c;
        tail->bottom = c;
        tail = c;
    }
}

void Linkedlist ::fatten_list(Node *head)
{
    Node *temp = head;
    Node *b_head, *b_tail, *curr;
    if (!temp->next || !temp->bottom)
    {
        if (!temp->next)
            return;
        else
            fatten_list(temp->next);
    }
    while (temp->bottom)
    {
        pair<Node *, Node *> l;
        l = find_limit(temp);
        Node *limit = l.first;
        curr = l.second;
        b_head = temp->bottom;
        b_tail = find_b_tail(temp->bottom, limit);
        if (curr == temp)
            curr->bottom = b_tail->bottom;
        else
            temp->bottom = b_tail->bottom;
        b_tail->bottom = NULL;
        b_tail->next = NULL;
        b_head = covert_b_list(b_head, b_tail);
        if (limit->next)
            b_tail->next = limit;
        else
            b_tail->next = NULL;
        curr->next = b_head;
    }
    fatten_list(temp->next);
}

pair<Node *, Node *> Linkedlist ::find_limit(Node *temp)
{
    Node *curr = temp;
    Node *tail = NULL;
    while (curr)
    {
        if (!curr->next || temp->bottom->data < curr->data) // TODO : change to temp->bottom->data <= curr->data
        {
            if (curr->next)
                return make_pair(curr, tail);
            else
            {

                if (tail->data < temp->bottom->data && curr->data < temp->bottom->data)
                    return make_pair(curr, curr);
                else
                    return make_pair(curr, tail);
            }
        }
        tail = curr;
        curr = curr->next;
    }
}

Node *Linkedlist ::find_b_tail(Node *temp, Node *limit)
{

    while (temp)
    {
        if (!temp->bottom || temp->bottom->data > limit->data)
        {
            return temp;
        }
        temp = temp->bottom;
    }
}

Node *Linkedlist ::covert_b_list(Node *b_head, Node *b_tail)
{
    Node *temp = b_head;
    while (temp->bottom)
    {
        temp->next = temp->bottom;
        temp->bottom = NULL;
        temp = temp->next;
    }

    return b_head;
}

void Linkedlist ::display()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}