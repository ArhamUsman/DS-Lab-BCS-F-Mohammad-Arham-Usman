// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    int data; node* next, *child;
    node (int d=-1, node*n=nullptr, node*c=nullptr){
        data=d;
        next=n;
        child=c;
    }
};

class multi_level_linked_list{
    node* head=nullptr; int size;
    void enter_child(node* parent){
        int x; node *prev=nullptr;
        while (1){
            cout<<"Enter an integer(-1 to exit child): ";
            cin>>x;
            if (x==-1) return;
            node* temp = new node(x, nullptr, nullptr);
            if (parent->child==nullptr){
                parent->child=temp;
                prev=temp;
            }
            else{
                prev->next=temp;
                prev=temp;
            }
        }
    }
    public:
    multi_level_linked_list(){
        int x; node *prev=nullptr;
        while (1){
            if (head!=nullptr) cout<<"Enter an integer(-1 to exit, -2 to enter child): ";
            else cout<<"Enter an integer(-1 to exit): ";
            cin>>x;
            if (x==-1) break;
            if (x==-2) {
                if (prev == nullptr) { 
                    cout<<"Error! No parent node to attach child.\n";
                    continue;
                }
                enter_child(prev);
                continue;
            }
            node* temp=new node(x, nullptr, nullptr);
            if (head==nullptr){
                head=temp;
                prev=temp;
            }
            else{
                prev->next=temp;
                prev=temp;
            }
        }
    }
    void display(){
        if (head==nullptr){
            cout<<"List is empty\n";
        }
        else{
            node*curr =head;
            while (curr!=nullptr){
                cout<<curr->data;
                if (curr->next!=nullptr||curr->child!=nullptr){
                    cout<<" -> ";
                }
                if (curr->child!=nullptr){
                    cout<<" ( ";
                    node* c=curr->child;
                    while (c!=nullptr){
                        cout<<c->data;
                        if (c->next!=nullptr){
                            cout<<" -> ";
                        }
                        c=c->next;
                    }
                    cout<<" ) ";
                    if (curr->next!= nullptr){
                        cout<<" -> ";
                    }
                }
                curr=curr->next;
            }
            cout<<endl;
        }
    }
    void flatten(){
        node *curr=head;
        while (curr!=nullptr){
            if (curr->child!=nullptr){
                node*temp=curr->next, *c=curr->child;
                curr->next=curr->child;
                curr->child=nullptr;
                while (c->next!=nullptr){
                    c=c->next;
                }
                c->next=temp;
            }
            curr=curr->next;
        }
    }
    ~multi_level_linked_list(){
        if (head==nullptr) return;
        node* curr=head;
        node* next=nullptr;
        while (curr!=nullptr){
            if (curr->child!=nullptr){
                node* c= curr->child;
                while(c!=nullptr){
                    next=c->next;
                    delete c;
                    c=next;
                }
            }
            next=curr->next;
            delete curr;
            curr=next;
        }
    }
};

int main() {
    multi_level_linked_list l1;
    cout<<"\nMultilevel Linked List: () donates child list:\n";
    l1.display();
    cout<<"Flattened Linked List: \n";
    l1.flatten();
    l1.display();
    return 0;
}