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
    bool less(node* p1, node*p2){
        if (p1==nullptr&&p2!=nullptr) return false;
        if (p2==nullptr) return true;
        return p1->data<p2->data;
    }
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
    
    void merge_sorted_list(linked_list& l2){
        node* curr1=head;
        node* curr2=l2.head;
        //check if any list if empty
        if (curr1==nullptr){
            head=curr2; return;
        }
        if (curr2==nullptr) return;
        
        //check if head needs to be replaced
        if (curr2!=nullptr && curr2->data<curr1->data){
            head=curr2;
            node* temp= head;
            while (temp->next!=nullptr&&temp->next->data<curr1->data){
                temp=temp->next;
            }
            curr2=temp->next;
            temp->next=curr1;
        }
        
        //insert nodes at the middle
        while (curr2!=nullptr){
            if (curr1->next==nullptr||curr1->next->data>curr2->data){
                node* temp=curr2->next;
                curr2->next=curr1->next;
                curr1->next=curr2;
                curr2=temp;
            }
            else{
                curr1=curr1->next;
            }
        }
        l2.head=nullptr;
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
    cout<<"Enter List 2:\n";
    linked_list l2;
    cout<<"List 1:\n";
    l1.display();
    cout<<"List 2:\n";
    l2.display();
    cout<<"After merging List 1 and List 2:\n";
    l1.merge_sorted_list(l2);
    l1.display();
    
    return 0;
}