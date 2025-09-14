// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
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
    void reverse_nodes(int k){
        vector<node*> nodes(k);
        bool first=true;
        int x=k; //x for each group, y for base
        node* curr=head, *prev=nullptr;
        while (1){
            x=0;
            for (int i=0; i<k; i++){
                nodes[i]=curr;
                if (curr!=nullptr){
                    curr=curr->next;
                    x++;
                }
            }
            if (x==0) break;
            if (first) {
                head=nodes[x-1];
                first=false;
            }
            else{
                prev->next=nodes[x-1];
            }
            for (int i=x-1; i>0; i--){
                nodes[i]->next=nodes[i-1];
            }
            prev=nodes[0];
            if (curr==nullptr) {
                prev->next=nullptr;
                break;
            }
        }
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
    cout<<"Enter List 1:\n";
    linked_list l1;
    l1.reverse_nodes(3);
    l1.display();
    return 0;
}