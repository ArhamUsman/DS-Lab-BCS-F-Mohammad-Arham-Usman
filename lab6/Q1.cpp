#include <iostream>
using namespace std;

class stack{
    int* arr, size, top;
    public:
    stack(int s=0){
        top=-1;
        if (s>0) size=s;
        else size=10;
        arr=new int[size];
    }
    bool push(int val){
        if (top>=size-1) {
            cout<<"Error! Stack is full\n";
            return false;
        }
        top++;
        arr[top]=val;
        cout<<val<<" pushed successfully\n";
        return true;
    }
    int pop(){
        if (top<0){
            cout<<"Error! Stack is empty\n";
            return 0;
        }
        cout<<arr[top]<<" popped successfully\n";
        return arr[top--];
    } 
    int peek(){
        if (top<0){
            cout<<"Error! Stack is empty\n";
            return 0;
        }
        return arr[top];
    } 
    void display(){
        cout<<"----------\n";
        if (top<0) cout<<"Stack is empty\n";
        else{
            cout<<"Displaying stack contents\n";
            for (int i=size-1; i>=0; i--){
                if (i>top) cout<<"-";
                else cout<<arr[i];
                if (i==top) cout<<" <-- top\n";
                else cout<<"\n";
            }
        }
        cout<<"----------\n";
    }
};

int main(){
    stack s1(3);
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
