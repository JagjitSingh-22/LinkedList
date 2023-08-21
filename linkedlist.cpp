#include<iostream>
using namespace std;

struct node{

    int data;
    struct node *next;
};

struct node* head, *tail=NULL;

void addNode(int data)
{
    struct node *newnode = new node();
    newnode->data = data;
    newnode->next=NULL;

    if (head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}

void insertAtHead(int data)
{
    struct node *temp = new node();
    temp->data=data;
    temp->next=head;
    head=temp;;
}

void insertAtTail(int data)
{
    struct node *temp = new node();
    temp->data=data;
    tail->next=temp;
    tail=temp;
}

void insertInBetween(int key,int data)
{
    struct node *temp = new node();
    temp->data=data;
    int c=1;
    struct node *headtemp = head;
    while(c<key-1)
    {
        headtemp=headtemp->next;
        c++;
    }
    struct node *after=headtemp->next;
    headtemp->next=temp;
    temp->next=after;

}

void countNode()
{
    int c=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    cout<<"The number of nodes are: " << c << endl;
}

void display()
{
    if(head==NULL)
    {
        cout<<"Linked List is empty";
        return;
    }

    struct node *current = head;

    cout<<"The Nodes of Linked List: " << endl;
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}

int main()
{
    addNode(1);
    display();
    addNode(2);
    display();
    insertAtHead(0);
    display();
    insertAtTail(3);
    display();
    insertInBetween(2,4);
    display();
    countNode();
}
