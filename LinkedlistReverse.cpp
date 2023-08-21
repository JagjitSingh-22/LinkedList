#include<iostream>
using namespace std;

struct node{

    int data;
    struct node *next;
};
struct node *head;
struct node *tail=NULL;

void createEmpLL()
{
    head=NULL;
}
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


void revLL()
{
    node *prev, *current, *nxt;
    prev=NULL;
    current=head;
    nxt=current->next;
    //while(nxt!=NULL)
    //{
    //    prev=current;
    //    current=nxt;
    //    nxt=current->next;
    //    current->next=prev;
    //}
    //head=current;
    while (current != NULL)
    {

        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    head = prev;
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

int main(){
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

    display();
    revLL();
    display();
}
