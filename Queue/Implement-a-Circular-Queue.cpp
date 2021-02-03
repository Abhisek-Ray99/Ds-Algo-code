// Implement a Circular Queue

#include<iostream>
#define SIZE 5
using namespace std;

class Queue{
    int items[SIZE];
    int front;
    int rear;
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        bool isFull(){
            if(front == 0 && rear == SIZE-1) return true;
            if(front == rear+1) return true;
            return false;
        }
        bool isEmpty(){
            if(front == -1) return true;
            else return false;
        }
        void QueueSize(){
            if(rear >= front) cout<<"\nSize : "<<(rear-front)+1;
            else cout<<"\nSize : "<<(SIZE-(front-rear)+1);
        }
        void addQueue(int element){
            if(isFull()) cout<<"Queue is Full"<<endl;
            else{
                if(front == -1) front = 0;
                rear = (rear+1) % SIZE;
                items[rear] = element;
                cout<<"\nInserted : "<<element;
            }
        }
        void deleteQueue(){
            int element;
            if(isEmpty()){
                cout<<"\nQueue is Empty"<<endl;
            }else{
                element = items[front];
                if(front == rear){
                    front = -1;
                    rear = -1;
                }else{
                    front = (front+1) % SIZE;
                }
                cout<<"\nDeleted Element : "<<element;
            }
        }
        void display(){
            int start;
            if(isEmpty()) cout<<"\nEmpty Queue "<<endl;
            else{
                cout<<"\nFront : "<<items[front];
                cout<<"\nItems -> ";
                for(start = front; start != rear; start=(start+1)%SIZE) cout<<items[start]<<" ";
                cout<<items[start];
                cout<<"\nRear : "<<items[rear];
            }
        }
};

int main(){
    Queue q;
    q.addQueue(12);
    q.addQueue(14);
    q.addQueue(16);
    q.addQueue(18);
    q.addQueue(20);
    q.display();
    q.QueueSize();
    q.deleteQueue();
    q.QueueSize();

    return 0;
}