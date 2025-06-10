/*The following program shows implementation of both front and tail varying  Queue using array(static Queue) having following basic operation:-
1)Enqueue
2)Dequeue
3)Display
The main function consists of some test cases you can use any test case you would like...
*/
#include<iostream>
using namespace std;
#define MAXSIZE 5
class Queue
{
    int front;
    int rear;
    int val;
    int queue[MAXSIZE];
    public:
    Queue()
    {
        front=0;
        rear=-1;
    }
    void enqueue(int val)
    {
        if(rear>=MAXSIZE-1)
        {
            cout<<"Queue is Full"<<endl;
        }
        else
        {
            rear++;
            queue[rear]=val;
            cout<<val<<" Enqueued"<<endl;
        }
    }
     void dequeue()
    {
        if(front>rear)
        {
            cout<<"Queue is Empty"<<endl;
        }
        else
        {
            val=queue[front];
            cout<<val<<" Dequeued"<<endl;
            front++;
        }
    }
    void display()
    {
        if(front>rear)
        {
            cout<<"Queue is Empty"<<endl;
        }
        else{
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<"\t";
        }
        cout<<endl;
    }

    }

};

int main()
{
    Queue queue;
     queue.enqueue(10);
     queue.enqueue(20);
     queue.enqueue(30);
     queue.enqueue(40);
     queue.enqueue(50);
     queue.enqueue(60);
     queue.enqueue(10);
     queue.display();
     queue.dequeue();
     queue.dequeue();
     queue.display();
     queue.dequeue();
     queue.dequeue();
     queue.dequeue();
     queue.dequeue();
     queue.display();
    
    return 0;

}


