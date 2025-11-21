#include<iostream>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    string key;
    Node(string d, string key, Node* n=nullptr){
        data=d; next=n;
        this->key=key;
    }
};

class HashTable{
    Node* buckets[11];
    int get_key(string s){
        int a=0;
        for (const auto&b:s){
            a+=b;
        }
        return a%11;
    }
    public:
    HashTable(){
        for (int i=0; i<11; i++){
            buckets[i]=nullptr;
        }
    }
    void insert(string k, string data){
        Node* temp=new Node(data, k);
        int key=get_key(temp->key);
        if (buckets[key]!=nullptr){
            Node*t=buckets[key];
            while (t!=nullptr){
                if (t->key==temp->key){
                    t->data=temp->data;
                    return;
                }
            }
        }
        temp->next=buckets[key];
        buckets[key]=temp;
        
    }
    void display(){
        for (int i=0; i<11; i++){
            Node*temp=buckets[i];
            while (temp!=nullptr){
                cout<<temp->data<<endl;
                temp=temp->next;
                
            }
        }
    }
    ~HashTable(){
        for (int i=0; i<10; i++){
            Node*temp=buckets[i], *tt;
            while (temp!=nullptr){
                tt=temp;
                temp=temp->next;
                delete tt;
            }
        }
    }
};


int main(){
    HashTable myhash;
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.display();
    cout<<"_______\n";
    myhash.insert("A", "zzzzz");
    myhash.display();
}