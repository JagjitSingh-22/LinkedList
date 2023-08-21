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

int countNode()
{
    int c=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    return c;
}

void midElement()
{
    int len=countNode();
    struct node *t1 = head;
    struct node *t2 = head;
    if(len%2==0)
    {
      while(t2!=NULL)
      {
        t1=t1->next;
        t2=t2->next;
        t2=t2->next;
      }
      cout<<"The middle element is: "<<t1->data;
    }
    else
    {
      while((t2->next)!=NULL)
      {
        t1=t1->next;
        t2=t2->next;
        t2=t2->next;
      }
      cout<<"The Middle element is: "<< t1->data <<endl;
    }
}

void thirdLastElement()
{
    int len=countNode();
    node *t1 = head;
    node *t2 = head;
    int c=0;
    while(t1->next!=NULL)
    {
        t1=t1->next;
        c++;
        //cout<<c<<endl<<endl;
        if(c>2)
        {
            //cout<<t2->data<<endl;
            t2=t2->next;
        }
    }
    cout<<"The Third Last Element is: " << t2->data << endl;
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
    createEmpLL();
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
    midElement();
    thirdLastElement();
}
