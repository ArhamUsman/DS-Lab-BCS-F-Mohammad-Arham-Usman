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
            return ' ';
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
            return ' ';
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

int precedence(char s){
    switch (s)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 2;
        break;
    case '*':
        return 3;
        break;
    case '/':
        return 4;
        break;
    case '^':
        return 5;
        break;
    
    default:
        return -1;
        break;
    }
}
string infixToPostfix(string infix){
    string postfix="";
    stack symbols;
    for (int i=0; i<infix.length(); i++){
        if (infix[i]>='0'&&infix[i]<='9'){
            postfix+=infix[i];
        }
        else if (infix[i]==')'){
            while (!symbols.isEmpty()&&symbols.peek()!='('){
                postfix+=symbols.pop();
            }
            if (symbols.peek()=='('){
                postfix+=symbols.pop();
            }
        }
        else if (precedence(infix[i])>precedence(symbols.peek())){
            symbols.push(infix[i]);
        }
        else if (infix[i]!='+'&&infix[i]!='-'&&infix[i]!='*'&&infix[i]!='/'&&infix[i]!='^'){
            continue;
        }
        else
    }
}

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
