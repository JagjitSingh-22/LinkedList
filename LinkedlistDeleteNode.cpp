#include<iostream>
using namespace std;

struct node{

    int data;
    struct node *next;
};
struct node *head;
struct node *tail = NULL;

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

int deleteAtBeg()
{
    int temp=head->data;
    node *ptr=head;
    head=head->next;
    free(ptr);
    return temp;
}

int deleteAtEnd()
{
    int temp;
    node *ptr,*p,*q;
    if(head->next==NULL)
    {
        temp=head->data;
        ptr=head;
        free(ptr);
        return temp;
    }
    else
    {
        p=NULL;
        q=head;
        while(q->next!=NULL)
        {
            p=q;
            q=q->next;
        }
        temp=q->data;
        free(q);
        p->next=NULL;
        return temp;
    }
}

int deleteInBetween(int key)
{
    int c=1;
    node *p = head;
    while(c<key-1)
    {
        p=p->next;
        c++;
    }
    node *ptr=p->next;
    int temp=ptr->data;
    p->next=ptr->next;
    free(ptr);
    return temp;
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
    cout<<endl<<"The Data got from the Deleted Node is: "<<deleteAtBeg()<<endl<<endl;
    display();
    cout<<endl<<"The Data got from the Deleted Node is: "<<deleteAtEnd()<<endl<<endl;
    display();
    cout<<endl<<"The Data got from the Deleted Node is: "<<deleteInBetween(2)<<endl<<endl;
    display();
}
