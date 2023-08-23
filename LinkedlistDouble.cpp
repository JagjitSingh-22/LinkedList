#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

struct node *head=NULL;
struct node *tail=NULL;

void addNode(int data)
{
    if(head==NULL)
    {
        node *newnode= new node();
        newnode->data=data;
        newnode->prev=NULL;
        head=newnode;
        tail=newnode;
    }
    else
    {
        node *newnode= new node();
        newnode->data=data;
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void insertAtHead(int data)
{
    node *temp = new node();
    temp->data=data;
    temp->next=head;
    head->prev=temp;
    head=temp;
    head->prev=NULL;
}

//Think of it as there is no tail and no addNode function
void insertAtEnd(int data)
{
    node *newnode = new node();
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void insertInBetween(int key,int data)
{
    node *newnode = new node();
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(key<1)
    {
        cout<<"Key should be greater than 1"<<endl;
        return;
    }
    else if(key==1)
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    else
    {
        node *temp=head;
        for(int i=1;i<key-1;i++)
        {
            if(temp->next!=NULL)
            {
                temp=temp->next;
            }
        }
        if(temp!=NULL)
        {
            newnode->next=temp->next;
            newnode->prev=temp;
            temp->next=newnode;

            if(newnode->next!=NULL)
            {
                newnode->next->prev=newnode;
            }
        }
        else
        {
            cout<<"The previous node is NULL"<<endl;
        }
    }
}

void printlist()
{
    node* temp = head;
    if(temp != NULL)
    {
        cout<<"The list contains: ";

        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    cout<<endl;
    }
    else
    {
        cout<<"The list is empty.\n";
    }
}

int main()
{
    int n;
    cout<<"Enter Number of elements wanted initially: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        addNode(a[i]);
    }

    printlist();

    insertAtHead(6);
    printlist();
    //cout<<head->next->next->data<<endl;
    //cout<<head->next->next->next->next->prev->data<<endl;
    insertAtEnd(7);
    printlist();

    insertInBetween(5,8);
    printlist();
}
