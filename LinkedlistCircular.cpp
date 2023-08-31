#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* addToEmpty(struct node* last, int data)
{
    if (last != NULL)
    {
        return last;
    }
  // allocate memory to the new node
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
  // assign data to the new node
    newnode->data=data;
  // make newnode as the last node
    last = newnode;
  // create link to itself as it is a circular linked list
    last->next = last;

    return last;
}

struct node *ins_beg(struct node *last, int data)
{
    struct node *newnode= new node;
    newnode->data=data;
    newnode->next=NULL;
    if(last==NULL)
    {
        newnode->next=newnode;
        last=newnode;
    }
    else
    {
        newnode->next=last->next;
        last->next=newnode;
    }
    return last;
}

struct node* addEnd(struct node* last, int data)
{
  // check if the LL is empty
    if (last == NULL)
    {
        return addToEmpty(last, data);
    }
  // allocate memory to the new node
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

  // add data to the node
    newnode->data = data;

  // store the address of the head node to next of newNode
    newnode->next = last->next;

  // point the current last node to the newNode
    last->next = newnode;

  // make newNode as the last node
    last = newnode;

    return last;
}

struct node* addAfter(struct node* last, int data, int item)
{
    // check if the list is empty
    if (last == NULL)
    {
        return NULL;
    }

    struct node *newnode, *p;

    p = last->next;
    do
    {
        // if the item is found, place newNode after it
        if (p->data == item)
        {
            // allocate memory to the new node
            newnode = (struct node*)malloc(sizeof(struct node));

            // add data to the node
            newnode->data = data;

            // make the next of the current node as the next of newNode
            newnode->next = p->next;

            // put newNode to the next of p
            p->next = newnode;

            // if p is the last node, make newNode as the last node
            if (p == last)
            {
                last = newnode;
            }
            return last;
        }

        p = p->next;
  }
  while (p != last->next);

  cout << "\nThe given node is not present in the list" << endl;
  return last;
}

void deleteNode(node* last, int key) {
    // if linked list is empty
    if (last == NULL)
    {
        return;
    }
    // if the list contains only a single node
    if (last->data == key && last->next == last)
    {
        delete last;
        last = NULL;
        return;
    }

    struct node *temp = last, *d;

    // if last is to be deleted
    if (last->data == key)
    {
        // find the node before the last node
        while (temp->next != last)
        {
            temp = temp->next;
        }
        // point temp node to the next of last i.e. first node
        temp->next = last->next;
        delete last;
        last = temp->next;
    }

    // travel to the node to be deleted
    while (temp->next != last && temp->next->data != key)
    {
        temp = temp->next;
    }

    // if node to be deleted was found
    if (temp->next->data == key)
    {
        d = temp->next;
        temp->next = d->next;
        delete d;
    }
}

void display(struct node *last)
{
    struct node *temp=last->next;
    if(temp==last)
    {
    cout<<temp->data<<" ";
    }
    else
    {
        while(temp->next!=last->next)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data;
    }
    /*
    struct node* p;
    if (last == NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }

    p=last->next;
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    while (p!=last->next);
    */
}

int main()
{
    struct node *last=new node;
    last=NULL;
    last=addToEmpty(last,9);
    last=ins_beg(last,10);
    last=ins_beg(last,11);
    last=ins_beg(last,12);
    last=ins_beg(last,13);
    last=addEnd(last,8);
    display(last);
    cout<<endl;
    last=addAfter(last,1,11);
    display(last);
    cout<<endl;
    deleteNode(last,1);
    display(last);

    //cout<<last->next->data << " "<< last->next->next->data << " " << last->next->next->next->data;
}
