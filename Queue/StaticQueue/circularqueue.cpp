/*
This program demonstrates the implementation of a Circular Queue using an array (static queue)
with the following basic operations:
    1) Enqueue - Insert an element at the rear of the queue
    2) Dequeue - Remove an element from the front of the queue
    3) Display - Print all elements from front to rear in circular order

The queue uses a fixed-size array and maintains two pointers: `front` and `rear`.
- `front` points to the first element in the queue (to be dequeued next)
- `rear` points to the position where the next element will be enqueued

Important Note:
- To distinguish between 'empty' and 'full' states, one slot in the array is left unused.
- So, if the array size is `n`, the queue can hold only up to `n - 1` elements.
- Full condition: (rear + 1) % n == front
- Empty condition: front == rear

This approach avoids ambiguity and makes circular queue logic clean and efficient.

The `main()` function includes a few test cases demonstrating:
    - Basic enqueue and dequeue operations
    - Handling of queue overflow and underflow
    - Wrap-around behavior of the circular structure
*/


#include<iostream>
using namespace std;
#define MAXSIZE 5
class Queue
{
    int front,rear,queue[MAXSIZE],val;
    public:
    Queue()
    {
        front=rear=0;
    }
    void enqueue(int val)
    {
        if(front==((rear+1)%(MAXSIZE)))
        {
            cout<<"Queue is full"<<endl;

        }
        else
        {
        queue[rear]=val;
        cout<<val<<" Enqueued"<<endl;
        rear=(rear+1)%MAXSIZE;
        }
    }
    void dequeue()
       {
        if(front==rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            val=queue[front];
            cout<<val<<" Dequeued"<<endl;
            front=(front+1)%MAXSIZE;
        }
       }
       void display()
       {
        if(front==rear)
        {
            cout<<"Queue is Empty"<<endl;
        }
        else
        {
            int frontcopy=front;
            while(frontcopy!=rear)
            {
             cout<<queue[frontcopy]<<"\t";
             frontcopy=(frontcopy+1)%MAXSIZE;
            }
            cout<<endl;
        }
       }

};


int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // Should show "Queue is Full" as N size array can hold n-1 elements acc to our logic

    q.display(); // Should print: 10 20 30 40

    // Dequeue two elements
    q.dequeue(); // Removes 10
    q.dequeue(); // Removes 20

    q.display(); // Should print: 30 40

    // Enqueue more to test wrap-around
    q.enqueue(60);
    q.enqueue(70);

    q.display(); // Should print: 30 40 60 70

    // Try to enqueue when full
    q.enqueue(80); // Should show "Queue is Full"

    // Dequeue all
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.display(); // Should print "Queue is Empty"

    // Try to dequeue from empty
    q.dequeue(); // Should show "Queue is Empty"

    return 0;
}