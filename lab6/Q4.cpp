#include <iostream>
using namespace std;

class Queue{
    int * arr, size, front, rear;
    
    public:
    Queue(int size=10){
        this->size=10;
        arr=nullptr;
        if (size>0){
            this->size=size;
            arr=new int[size];
        }
        front=-1; rear=-1;
    }
    //enqueue at rear
    void enqueue(int val){
        if (isFull()){
            cout<<"Cannot Enqueue: Error Circular Queue is full\n";
            return;
        }
        if (isEmpty()) front=rear=0;
        else rear=(rear+1)%size;
        arr[rear]=val;
        cout<<"Enqueued: "<<val<<endl;
    }
    
    //dequeue at front
    int dequeue(){
        if (isEmpty()){
            cout<<"Cannot Dequeue: Error circular Queue is empty\n";
            return -1;
        }
        int val=arr[front];
        if (front==rear) front=rear=-1;
        else front=(front+1)%size;
        cout<<"Dequeued: "<<val<<endl;
        return val;
    }
    //display
    void display(){
        cout<<"----------\n";
        if (isEmpty()) {
            cout<<"Cannot Display: Error Queue is empty\n";
            return;
        }
        if (front == rear) cout<<arr[front]<<" <- front+rear\n";
        else{
            cout<<arr[front]<<" <- front\n";
            int temp=(front+1)%size;
            while (temp!=rear){
                cout<<arr[temp]<<endl;
                temp=(temp+1)%size;
            }
            cout<<arr[rear]<<" <- rear\n";
        }
        cout<<"----------\n";
    }

    //empty/full
    bool isFull(){
        return (((rear+1)%size)==front);
    }
    bool isEmpty(){
        return (front==-1&&rear==-1);
    }

};

int main(){
    Queue q1(5);
    q1.display();
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.display();
    q1.dequeue();
    q1.display();   
    q1.enqueue(6);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    
}
