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
class Node{//Class for the node

    public://Public so that other class can access its data
    int data;
    Node *next;

    Node(int val){//Parametrized Constructor
        data=val;
        next=NULL;
    }


    
};

class linked_list{
    Node* head;//Head pointer
    Node* tail;//Tail Pointer
    public:
    linked_list()//constructor
    {
        head=tail=NULL;
    }
    void push_front(int val)
    {
        Node* newnode=new Node(val);//Dynamically created a instance(object) of Node class and the newnode has its adress
        //if we had done Node newnode only it would be static and gets deleted after the program comes out of the loop
        if(head==NULL)//the list is empty
        {
           head=tail=newnode;
           return;
        }
        else{//If list isnt empty i.e. has some elemnts present
            newnode->next=head;
            head=newnode;
        }
    }

    
    void printlist()
    {
       
        if(head==NULL)
        {
           cout<<"Linked List is empty"<<endl;
           return;
        }
        else{
             Node* temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }

    }
    void push_back(int val)
    {
        Node* newnode=new Node(val);
        
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else{
        
            tail->next=newnode;
            tail=newnode;
    }

    }
    void pop_front()
    {
        
        if(head==NULL)
        {
            cout<<"List is empty nothing to pop"<<endl;
            return;
        }
        else{
            Node* temp=head;
            head=head->next;
            delete temp;

        }
    }
    void pop_back()
    {
        if(head==NULL)
        {
            cout<<"Can't Pop linked List is empty"<<endl;
           return;
        }
      else if(head==tail)
        {
            delete tail;
            head=tail=NULL;
        }
        else{
            Node* temp=head;
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
           temp->next=NULL;
           delete tail;
           tail=temp;

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
void insert(int val,int position)
{
    int size=sizeoflist();
    if(head==NULL||position==0)
    {
        push_front(val);
        return;
    }
    else if(position==size)
    {
        push_back(val);
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
    else
    {
        cout<<val<<" Cannot be inserted,Error Position !!!"<<endl;
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
~linked_list() //Destructor to cleanup the memory after program ends so no memory leaks
{
    Node* temp = head;
    while(temp != NULL) {
        Node* savetempnext=temp->next;
         delete temp;
        temp=savetempnext;
       
    }
}

};
int main()
{
    linked_list ll;

    // Test push_front and push_back
    ll.push_front(10);      // List: 10
    ll.push_back(20);       // List: 10->20
    ll.push_front(5);       // List: 5->10->20
    ll.push_back(25);       // List: 5->10->20->25
    ll.printlist();

    // Test sizeoflist
    cout << "Size: " << ll.sizeoflist() << endl;

    // Test insert at various positions
    ll.insert(1, 0);        // Insert at head: 1->5->10->20->25
    ll.insert(15, 3);       // Insert in middle: 1->5->10->15->20->25
    ll.insert(30, ll.sizeoflist()); // Insert at end: 1->5->10->15->20->25->30
    ll.printlist();

    // Test deleteAtPosition
    ll.deleteAtPosition(0); // Delete head: 5->10->15->20->25->30
    ll.deleteAtPosition(2); // Delete middle: 5->10->20->25->30
    ll.deleteAtPosition(ll.sizeoflist()-1); // Delete tail: 5->10->20->25
    ll.printlist();

    // Test pop_front and pop_back
    ll.pop_front();         // Remove head: 10->20->25
    ll.pop_back();          // Remove tail: 10->20
    ll.printlist();

    // Test edge cases
    ll.deleteAtPosition(10); // Invalid position
    ll.pop_front();          // 20
    ll.pop_back();           // List becomes empty
    ll.printlist();          // Should print "Linked List is empty"
    ll.pop_back();           // Try pop on empty list

    // Final size
    cout << "Final Size: " << ll.sizeoflist() << endl;

    return 0;
}