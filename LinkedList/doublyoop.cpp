#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val)
    {
        data=val;
        next=prev=NULL;
    }
};
class doubly_ll
{
Node* head;
Node* tail;
public:
doubly_ll()
{
    head=tail=NULL;
}
void push_front(int val)
{
    Node* newnode=new Node(val);
    if(head==NULL)
    {
        head=tail=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }

}
void push_back(int val)
{
    Node* newnode=new Node(val);
    if(head==NULL)
    {
        head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void pop_front()
{
    if(head==NULL)
    {
        cout<<"The list is empty cant pop"<<endl;
    }
    else if(head==tail)
    {
        delete head;
        head=tail=NULL;
    }
    else
    {
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
    }
}
void pop_back()
{
    if(head==NULL)
    {
        cout<<"The list is empty cant pop"<<endl;
    }
    else if(head==tail)
    {
        delete tail;
        head=tail=NULL;
    }
    else
    {
        Node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
    }
}
void insert(int val,int position)
{   int size=sizeoflist();
    if(head==NULL||position==0)
    {
        push_front(val);
    }
    else if(position<size)
    {
        Node* newnode=new Node(val);
        Node* temp=head;
        int count=0;
        while(count<position-1)
        {
            temp=temp->next;
            count++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
        

    }
    else if(position==size)
    {
        push_back(val);
    }
    else
    {
        cout<<"Positional error"<<endl;
    }

}
int sizeoflist()//Returns the size of our linked list
{
        Node* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
}
void print_list()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
~doubly_ll()
{
Node* temp=head;
while(temp!=NULL)
{
    Node* savetempnext=temp->next;
    delete temp;
    temp=savetempnext;
}
}
void deleteAtPosition(int position)
{
    int size=sizeoflist();
    Node* temp=head;
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(position==size-1)
    {
     pop_back();
    }
    else if(position==0)
    {
        pop_front();
    }
    else if(position>=size||position<0)
    {
        cout<<"Positional Error"<<endl;
    }
    else{
    int count=0;
    while(count!=position)
    {
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
}
}
};
int main()
{
    doubly_ll dll;
    
    dll.push_front(30);
    dll.push_front(20);
    dll.push_front(40);
    dll.push_front(90);
    dll.push_front(100);
    dll.deleteAtPosition(4);
    dll.print_list();
    return 0;
}