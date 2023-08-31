#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *push(struct node *top,int data)
{
    struct node *newnode= new node;
    newnode->data=data;
    newnode->next=top;
    top=newnode;

    return top;
}

struct node *pop(struct node *top)
{
    if(top==NULL)
    {
        cout<<"Caution: UnderFlow";
        return NULL;
    }

    struct node *ptr=top;
    top=top->next;
    delete ptr;

    return top;
}

void display(struct node *top)
{
    if(top==NULL)
    {
        cout<<"Stack is empty";
        return;
    }

    struct node *current = top;

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
    struct node * top= NULL;
    top=push(top,5);
    top=push(top,4);
    display(top);
    top=pop(top);
    display(top);
    top=push(top,9);
    display(top);
}
