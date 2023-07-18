//
//  main.cpp
//  reversing_a_linked_list
//
//  Created by Uby H on 18/07/23.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL;
void create(int x)
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
        last=t;
    }
    else
    {
        last->next=t;
        last=t;
    }
}
void display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void reverse(struct Node *p)
{
    struct Node *p1;
    struct Node *q;
    q=p->next;
    p->next=NULL;
    while(q->next!=NULL)
    {
        p1=q->next;
        q->next=p;
        p=q;
        q=p1;
    }
    q->next=p;
    first=q;
}
int main()
{
    int n,x;
    cout<<"Enter the number of elements in the linked list : "<<endl;
    cin>>n;
    cout<<"Enter the elemens of the linked list : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        create(x);
    }
    cout<<"The original linked list is given by : "<<endl;
    display(first);
    cout<<"The reversed linked list is given by : "<<endl;
    reverse(first);
    display(first);
    return 0;
}
