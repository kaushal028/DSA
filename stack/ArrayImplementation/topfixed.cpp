#include<iostream>
using namespace std;
#define MAXSIZE 5
class Stack
{
int bos;//bottom of stack
int item;//value to push in stack
int stack[MAXSIZE];//Stack array
public:

Stack() //Constructor to initialize BOS=0
{
bos=0;
}
void push()//Method to push 
{
    if(bos==MAXSIZE)
   {
     cout<<"Stack Overflow!!!"<<endl;
   }
    else
   {
     cout<<"Enter the value to be pushed in the stack"<<endl;
     cin>>item;
   
     for(int i=bos;i>0;i--)
       {
         stack[i]=stack[i-1];//Moves value from top to bottom 
        }
     stack[0]=item;
     bos++;
        
    }
}
void pop()
{
    if(bos==0)
   {
         cout<<"Stack Underflow"<<endl;
     }
    else
    {
        item=stack[0];
        cout<<item<<" got popped!!!"<<endl;
         bos--;
        for(int i=0;i<bos;i++)
        {
            
            stack[i]=stack[i+1];
        }
       

    }
}
void display()
{
    if(bos==0)
    {
        cout<<"Stack is Empty"<<endl;
        
    }
    else
    {
        for(int i=0;i<bos;i++)
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