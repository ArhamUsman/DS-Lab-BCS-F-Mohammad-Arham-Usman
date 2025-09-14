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

class singly_linked_list{
    node* head;
    public:
    singly_linked_list(){
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
    ~singly_linked_list(){
        node* curr=head;
        node* next;
        while (curr!=nullptr){
            next=curr->next;
            delete curr;
            curr=next;
        }
    }
    friend class circular_linked_list;
    friend class doubly_linked_list;
};

class circular_linked_list{
    node* head;
    public:
    circular_linked_list(singly_linked_list& s1){
        if (s1.head==nullptr){
            head=nullptr;
            return;
        }
        head=new node(s1.head->data, nullptr);
        node* prev=head;
        node* temp= s1.head->next;
        while (temp!=nullptr){
            node* new_node=new node(temp->data, nullptr);
            prev->next=new_node;
            prev=new_node;
            temp=temp->next;
        }
        prev->next=head;
    }
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

class node_d{
    public:
    char data; node_d* next, *prev;
    node_d (node_d *p=nullptr, char d='-', node_d *n=nullptr){
        prev=p;
        data=d;
        next=n;
    }
};
class doubly_linked_list{
    node_d* head;
    public:
    doubly_linked_list(singly_linked_list& s1){
        if (s1.head==nullptr) {
            head=nullptr;
            return;
        }
        head=new node_d(nullptr, s1.head->data, nullptr);
        node_d *prev;
        node *curr;
        curr=s1.head->next;
        prev=head;
        while (curr!=nullptr){
            node_d* new_node=new node_d(prev, curr->data, nullptr);
            prev->next=new_node;
            prev=new_node;
            curr=curr->next;
        }
    }
    doubly_linked_list(){
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
            head=new node_d(nullptr, d, nullptr);
        }
        else{
            node_d* temp=new node_d(nullptr, d, nullptr);
            node_d* curr=head;
            
            while(curr->next!=nullptr){
                curr=curr->next;
            }
            curr->next=temp;
            temp->prev=curr;
        }
    }
    void display(){
        if (head==nullptr){
            cout<<"List is empty\n";
        }
        else{
            node_d *curr = head;
            while (curr->next!=nullptr){
                cout<<curr->data<<" | ";
                curr=curr->next;
            }
            cout<<curr->data<<endl;
        }
    }
    ~doubly_linked_list(){
        if (head==nullptr) return;
        node_d* curr=head;
        node_d* next;
        while (curr!=nullptr){
            next=curr->next;
            delete curr;
            curr=next;
        }
    }
};

int main() {
    cout<<"Enter List 1:\n";
    singly_linked_list l1;
    cout<<"Displaying singly linked list\n";
    l1.display();
    circular_linked_list l2(l1);
    cout<<"Displaying circular linked list\n";
    l2.display();
    doubly_linked_list l3(l1);
    cout<<"Displaying doubly linked list\n";
    l3.display();
    return 0;
}