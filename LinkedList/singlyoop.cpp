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
            cout<<"Linked List is empty"<<endl;
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
void insert(int val,int position)
{
    int size=sizeoflist();
    if(head==NULL||position==0)
    {
        push_front(val);
        return;
    }
    
    else if(position<=size)
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
        cout<<val<<" cannot be inserted,Error Position !!!"<<endl;
    }
}
int sizeoflist()
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
~linked_list() 
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
    ll.push_front(20);
    ll.push_front(30);
    ll.push_back(60);
    ll.push_front(40);
    ll.push_back(50);

    ll.insert(70,3);
    ll.insert(60,7);
    ll.pop_back();

 ll.insert(70,6);
    cout<<"Linked List contains:"<<endl;

    ll.printlist();
    return 0;
}