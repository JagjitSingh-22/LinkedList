#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *tail=NULL;

struct node *push(struct node *top,int data)
{
    struct node *newnode= new node;
    newnode->data=data;
    newnode->next=top;
    if(top==NULL)
    {
        tail=newnode;
    }
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
    struct node * stk1= NULL;
    stk1=push(stk1,5);
    stk1=push(stk1,4);

    struct node * stk2= NULL;
    stk2=push(stk2,5);
    stk2=push(stk2,6);

    display(stk1);
    display(stk2);

    tail->next=stk1;

    display(stk2);
}
