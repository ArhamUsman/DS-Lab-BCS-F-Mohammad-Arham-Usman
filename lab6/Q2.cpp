#include <iostream>
using namespace std;

class Node{
    public:
    int data; Node* link;
    Node(int d=0, Node* l=nullptr){
        data=d; link=l;
    }
};

class stack{
    Node* top;
    public:
    stack(){
        top=nullptr;
    }
    bool push(int val){
        Node* new_node=new Node(val, top);
        top=new_node;
        cout<<val<<" pushed successfully\n";
        return true;
    }
    int pop(){
        if (top==nullptr){
            cout<<"Error! Stack is empty\n";
            return 0;
        }
        cout<<top->data<<" popped successfully\n";
        Node* temp=top;
        top=top->link;
        int x=temp->data;
        delete temp;
        return x;
    } 
    int peek(){
        if (top==nullptr){
            cout<<"Error! Stack is empty\n";
            return 0;
        }
        return top->data;
    } 
    void display(){
        cout<<"----------\n";
        if (top<0) cout<<"Stack is empty\n";
        else{
            cout<<"Displaying stack contents\n";
            Node* temp=top;
            while (top!=nullptr){
                cout<<top->data<<endl;
                top=top->link;
            }
        }
        cout<<"----------\n";
    }
};

int main(){
    stack s1;
    s1.push(5);
    s1.display();
    s1.push(4);
    s1.push(3);
    s1.display();
    int x=s1.peek();
    cout<<"Peeked: "<<x<<endl;
    s1.pop();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
}
