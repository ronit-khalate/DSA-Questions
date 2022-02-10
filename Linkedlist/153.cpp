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
    Node*find_targets_position(Node*);
    queue <Node*>save_base_list(Node*);
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
            if (x == -1)
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
    queue<Node*>a=save_base_list(head);
    Node*base_node=a.front();
    a.pop();
    while (base_node)
    {
        while (base_node->bottom)
        {
            Node*target=base_node->bottom;
            Node*position_of_target=find_targets_position(target);
            base_node->bottom=target->bottom;
            target->bottom=NULL;
            target->next=position_of_target->next;
            position_of_target->next=target;

        }
        base_node=a.front();
        a.pop();
        
    }
    
}

Node*Linkedlist ::find_targets_position(Node*target)
{
    Node*position=NULL,*position_head=head;

    while (position_head)
    {
        if(position_head->data>target->data)
        {
            if(position)
                return position;
            else
                return position_head;
        }
        position=position_head;
        position_head=position_head->next;
    }
    return position;
}

queue<Node*> Linkedlist ::save_base_list(Node*head)
{
    Node*temp=head;
    queue<Node*> a;

    while (temp)
    {
        a.push(temp);
        temp=temp->next;
    }
    a.push(NULL);
    return a;
    
}



void Linkedlist ::display()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout<<" NULL";  
    cout<<"\n";
}