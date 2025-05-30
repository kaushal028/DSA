//Simple Implementation of Stack using array by top varying method or bottom fixed method
#include<iostream>
using namespace std;
#define MAXSIZE 5
class Stack
{
int top;
int item;
int stack[MAXSIZE];
public:
Stack()
{
top=-1;
}
void push()
{
    if(top==MAXSIZE-1)
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        cout<<"Enter the value to be pushed"<<endl;
        cin>>item;
         top++;
        stack[top]=item;
    }   
       
}
void pop()
{
    if(top==-1)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        item=stack[top];
        cout<<item<<" is popped"<<endl;
        top--;

    }
}
    void display()
{
    if(top==-1)
    {
        cout<<"Stack is Empty"<<endl;
        
    }
    else
    {
        for(int i=top;i>=0;i--)
       {
         cout<<stack[i]<<endl;
        }
    }
}   
};
int main()
{
    Stack st;
    
    do
    {
    int choice;
    cout<<"1)PUSH\n2)POP\n3)DISPLAY\n4)EXIT"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 1:
        st.push();
        break;
        case 2:
        st.pop();
        break;
        case 3:
        st.display();
        break;
        case 4:
        return 0;
    }

    } while (true);
    
}
