#include <iostream>
using namespace std;

class Node{
    public:
    char data; Node* link;
    Node(char d=0, Node* l=nullptr){
        data=d; link=l;
    }
};

class stack{
    Node* top;
    public:
    stack(){
        top=nullptr;
    }
    bool isEmpty(){
        return top==nullptr;
    }
    bool push(char val){
        Node* new_node=new Node(val, top);
        top=new_node;
        cout<<val<<" pushed successfully\n";
        return true;
    }
    char pop(){
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
    char peek(){
        if (top==nullptr){
            cout<<"Error! Stack is empty\n";
            return 0;
        }
        return top->data;
    } 
    void display(){
        cout<<"----------\n";
        if (top==nullptr) cout<<"Stack is empty\n";
        else{
            cout<<"Displaying stack contents\n";
            Node* temp=top;
            while (temp!=nullptr){
                cout<<temp->data<<endl;
                temp=temp->link;
            }
        }
        cout<<"----------\n";
    }
    ~stack(){
        while (top!=nullptr){
            Node*temp=top;
            top=top->link;
            delete temp;
        }
    }
};

int main(){
    stack s1;
    s1.push('5');
    s1.display();
    s1.push('4');
    s1.push('3');
    s1.display();
    char x=s1.peek();
    cout<<"Peeked: "<<x<<endl;
    s1.pop();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
}
