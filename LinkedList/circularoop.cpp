/*The following circular linked list has following operations:-
1)Push_front
2)Push-back
3)Pop_front
4)Pop_back
5)Insert at any position
6)Delete at any position
7)Print the list
 and also a size method that gives us the size of the list
Feel Free to use any testcases*/
#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node* next;
Node(int val)
{
    data=val;
    next=NULL;
}
};
class circular_ll
{
Node* head;
Node* tail;
public:
circular_ll()
{
    head=tail=NULL;
}
~circular_ll()
{
if(head==NULL)
{
    return;
}
else{
    Node* temp=head;
    do
    {
        Node* storetempnext=temp->next;
        delete temp;
        temp=storetempnext;
    } while (temp!=head);
    head=tail=NULL;
    
}
}

void push_front(int val)
{
    Node* newnode=new Node(val);
    if(head==NULL)
    {
        head=tail=newnode;
        tail->next=head;
    }
    else
    {
      newnode->next=head;
      head=newnode;
      tail->next=head;
    }
}
void push_back(int val)
{ 
    Node* newnode=new Node(val);
    if(head==NULL)
    {
        head=tail=newnode;
        tail->next=head;
    }
    else
    {
   tail->next=newnode;
   tail=newnode;
   tail->next=head;
    }
}
void pop_front()
{
    if (head==NULL)
    {
        cout<<"Nothing to Pop"<<endl;
    }
    else
    {
        Node* temp=head;
        head=head->next;
        tail->next=head;
        delete temp;
    }
}
void pop_back()
{
    if (head==NULL)
    {
        cout<<"Nothing to Pop"<<endl;
    }
    else if(head==tail)
    {
        delete head;
        head=tail=NULL;
    }
    else
    {
        Node* temp=head;
   while(temp->next->next!=head)
   {
    temp=temp->next;
   }
   tail=temp;
   temp=tail->next;
   tail->next=head;
   delete temp;
    
}
}

void insert(int val,int position)
{
 int size=get_size();
    if(head==NULL||position==0)
    {
        push_front(val);
        return;
    }
    
    else if(position<size)
    {
        int count=0;
        Node* newnode=new Node(val);
        Node* temp=head;
        while(count!=position-1)
        {
          temp=temp->next;
          count++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    else if(position == size)
     {
    push_back(val);
    return;
    }
    else
    {
        cout<<val<<" cannot be inserted,Error Position !!!"<<endl;
    }
}

int get_size()
{
    Node* temp=head;
int count=0; 
if(head==NULL)
{
    return 0;
}
else{
   do
    {
    count++;
    temp=temp->next;
    }
   while(temp!=head);
return count;

}
}


void print_list()
{
Node* temp=head;
if(head==NULL)
{
    cout<<"List is empty"<<endl;
}
else{
    do
    {
    cout<<temp->data<<"->";
    temp=temp->next;
    }
   while(temp!=head);
   cout<<"HEAD"<<endl;
  
}
}
void deleteAtPosition(int position)
{
int size=get_size();
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
    while(count!=position-1)
    {
        temp=temp->next;
        count++;
    }
    Node* storetemp=temp->next;
   temp->next=temp->next->next;
   delete storetemp;
}

}
};

int main()
{
    circular_ll cll;

    // Test push_front and push_back
    cll.push_front(10);      // List: 10
    cll.push_back(20);       // List: 10->20
    cll.push_front(5);       // List: 5->10->20
    cll.push_back(25);       // List: 5->10->20->25
    cll.print_list();

    // Test get_size
    cout << "Size: " << cll.get_size() << endl;

    // Test insert at various positions
    cll.insert(1, 0);        // Insert at head: 1->5->10->20->25
    cll.insert(15, 3);       // Insert in middle: 1->5->10->15->20->25
    cll.insert(30, cll.get_size()); // Insert at end: 1->5->10->15->20->25->30
    cll.print_list();

    // Test deleteAtPosition
    cll.deleteAtPosition(0); // Delete head: 5->10->15->20->25->30
    cll.deleteAtPosition(2); // Delete middle: 5->10->20->25->30
    cll.deleteAtPosition(cll.get_size()-1); // Delete tail: 5->10->20->25
    cll.print_list();

    // Test pop_front and pop_back
    cll.pop_front();         // Remove head: 10->20->25
    cll.pop_back();          // Remove tail: 10->20
    cll.print_list();

    // Test edge cases
    cll.deleteAtPosition(10); // Positional Error
    cll.pop_front();          // 20
    cll.pop_back();           // List becomes empty
    cll.print_list();         // Should print "List is empty"
    cll.pop_back();           // Try pop on empty list

    // Final size
    cout << "Final Size: " << cll.get_size() << endl;

    return 0;
}