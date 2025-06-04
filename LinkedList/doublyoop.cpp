/*The following doubly linked list has following operations:-
1)Push_front
2)Push-back
3)Pop_front
4)Pop_back
5)Insert at any position
6)Delete at any position
7)Print the list
 and also a size method that gives us the size of the list
 feel free to use any test cases */
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
        return;
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
    else if(position>=size||position<0)
    {
        cout<<"Positional Error"<<endl;
    }
    else if(position==size-1)
    {
     pop_back();
    }
    else if(position==0)
    {
        pop_front();
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

    // Test push_front and push_back
    dll.push_front(10);      // List: 10
    dll.push_back(20);       // List: 10<->20
    dll.push_front(5);       // List: 5<->10<->20
    dll.push_back(25);       // List: 5<->10<->20<->25
    dll.print_list();

    // Test sizeoflist
    cout << "Size: " << dll.sizeoflist() << endl;

    // Test insert at various positions
    dll.insert(1, 0);        // Insert at head: 1<->5<->10<->20<->25
    dll.insert(15, 3);       // Insert in middle: 1<->5<->10<->15<->20<->25
    dll.insert(30, dll.sizeoflist()); // Insert at end: 1<->5<->10<->15<->20<->25<->30
    dll.print_list();

    // Test deleteAtPosition
    dll.deleteAtPosition(0); // Delete head: 5<->10<->15<->20<->25<->30
    dll.deleteAtPosition(2); // Delete middle: 5<->10<->20<->25<->30
    dll.deleteAtPosition(dll.sizeoflist()-1); // Delete tail: 5<->10<->20<->25
    dll.print_list();

    // Test pop_front and pop_back
    dll.pop_front();         // Remove head: 10<->20<->25
    dll.pop_back();          // Remove tail: 10<->20
    dll.print_list();

    // Test edge cases
    dll.deleteAtPosition(10); // Positional Erorr
    dll.pop_front();          // 20
    dll.pop_back();           // List becomes empty
    dll.print_list();         // Should print "NULL"
    dll.pop_back();           // Try pop on empty list

    // Final size
    cout << "Final Size: " << dll.sizeoflist() << endl;

    return 0;
}