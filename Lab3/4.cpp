// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    int data; node* next;
    node (int d=-1, node*n=nullptr){
        data=d;
        next=n;
    }
};

class circular_linked_list{
    node* head; int size;
    public:
    circular_linked_list(){
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
    circular_linked_list(int n){
        if (n==0){
            head=nullptr;
            return;
        }
        head=new node(1, nullptr);
        node* curr=head;
        for (int i=1; i<n; i++){
            node* new_node=new node(i+1, nullptr);
            curr->next=new_node;
            curr=new_node;
        }
        curr->next=head;
        size=n;
    }
    int Josephus_Problem(int k){
        if (head==nullptr) return -1;
        node *x=head, *prev=nullptr;
        while (x->next!=head){
            x=x->next;
        }
        prev=x;
        x=x->next;
        while (x->next!=x){
            for (int i=1; i<k; i++){
                prev=x;
                x=x->next;
            }
            prev->next=x->next;
            delete x;
            x=prev->next;
        }
        head=x;
        return x->data;
    }
    void push_back(int d){
        if (head==nullptr){
            head=new node(d, nullptr);
            head->next=head;
        }
        else{
            node* temp=new node(d, head);
            node* curr=head;
            while(curr->next!=head){
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
            while (curr->next!=head){
                cout<<curr->data<<" | ";
                curr=curr->next;
            }
            cout<<curr->data<<endl;
        }
    }
    ~circular_linked_list(){
        if (head==nullptr) return;
        node* curr=head->next;
        node* next;
        while (curr!=head){
            next=curr->next;
            delete curr;
            curr=next;
        }
        delete head;
    }
};

int main() {
    int N, k;
    cout<<"Enter N: ";
    cin>>N;
    cout<<"Enter k: ";
    cin>>k;
    circular_linked_list l1(N);
    cout<<l1.Josephus_Problem(k);
    
    return 0;
}