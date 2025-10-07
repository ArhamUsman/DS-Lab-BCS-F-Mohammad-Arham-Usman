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
    //enqueue
    void enqueue(int val){
        if (isFull()){
            cout<<"Cannot Enqueue: Error Linear Queue is full\n";
            return;
        }
        rear++;
        arr[rear]=val;
        if (front==-1) front =0;
        cout<<"Enqueued: "<<val<<endl;
    }
    //dequeue
    int dequeue(){
        if (isEmpty()){
            cout<<"Cannot Dequeue: Error Linear Queue is empty\n";
            return -1;
        }
        int val=arr[front];
        front++;
        if (front>rear) {
            front=-1; rear=-1;
        }
        cout<<"Dequeued: "<<val<<endl;
        return val;
    }
    //display
    void display(){
        cout<<"----------\n";
        for (int i=0; i<size; i++){
            if (i>rear||i<front){
                cout<<"-\n";
            }
            else if (i==front&&i==rear){
                cout<<arr[front]<<" <- front+rear\n";
            }
            else if (i==front){
                cout<<arr[front]<<" <- front\n";
            }
            else if (i==rear){
                cout<<arr[i]<<" <- rear\n";
            }
            else{
                cout<<arr[i]<<"\n";
            }
        }
        cout<<"----------\n";
    }

    //empty/full
    bool isFull(){
        return rear==size-1;
    }
    bool isEmpty(){
        return front==-1||front>rear;
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
}
