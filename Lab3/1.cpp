// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class node{
    public:
    char data; node* next;
    node (char d='-', node*n=nullptr){
        data=d;
        next=n;
    }
};


class linked_list{
    node* head;
    public:
    linked_list(){
        head=nullptr;
        string d;
        while (1){
            cout<<"Enter data (char)(-1 to exit): ";
            cin>>d;
            if (d=="-1") break;
            if (d.length()!=1){
                cout<<"Invalid data! Try again\n";
                continue;
            }
            push_back(d[0]);
        }
    }
    void push_back(int d){
        if (head==nullptr){
            head=new node(d, nullptr);
        }
        else{
            node* temp=new node(d, nullptr);
            node* curr=head;
            while(curr->next!=nullptr){
                curr=curr->next;
            }
            curr->next=temp;
        }
    }
    void display(){
        if (head==nullptr){
            cout<<"List is empty\n";
        }
        else{
            node*curr =head;
            while (curr->next!=nullptr){
                cout<<curr->data<<" | ";
                curr=curr->next;
            }
            cout<<curr->data<<endl;
        }
    }
    bool is_palindrome(){
        if (head==nullptr){
            cout<< "Error! List is empty\n";
            return false;
        }
        string s;
        node* curr=head;
        while (curr!=nullptr){
            s+=curr->data;
            curr=curr->next;
        }
        int i=0, j=s.length()-1;
        while (i<j){
            if (s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    ~linked_list(){
        node* curr=head;
        node* next;
        while (curr!=nullptr){
            next=curr->next;
            delete curr;
            curr=next;
        }
    }
};

int main() {
    linked_list l1;
    cout<<"\nDisplaying Linked list: \n";
    l1.display();
    cout<<endl;
    if (l1.is_palindrome()) cout<<"List is palindrome\n";
    else cout<<"List is not palindrome.\n";
    return 0;
}