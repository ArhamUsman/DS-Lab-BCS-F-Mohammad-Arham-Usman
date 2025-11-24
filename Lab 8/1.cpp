#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d, Node* l, Node* r){
        data=d;
        left=l;
        right=r;
    }
};

class BST{
    Node* root;
    void inOrderTraverse(Node* root){
        if (root!=nullptr){
            inOrderTraverse(root->left);
            cout<<root->data<<" | ";
            inOrderTraverse(root->right);
        }
    }
    void preOrderTraverse(Node* root){
        if (root!=nullptr){
            cout<<root->data<<" | ";
            preOrderTraverse(root->left);
            preOrderTraverse(root->right);
        }
    }
    void postOrderTraverse(Node* root){
        if (root!=nullptr){
            postOrderTraverse(root->left);
            postOrderTraverse(root->right);
            cout<<root->data<<" | ";
        }
    }
    int getMax(Node* root){
        if (root->right==nullptr) return root->data;
        return getMax(root->right);
    }
    Node* deleteBST(Node*&root, int data){
        if (root==nullptr) return root;
        if (data<root->data) root->left = deleteBST(root->left, data);
        else if (data>root->data) root->right = deleteBST(root->right, data);
        //Data found
        else{
            //Case 01: No child
            if (root->left==nullptr&&root->right==nullptr){
                delete root;
                return nullptr;
            }
            //Case 02: 1 child
            else if (root->left==nullptr){
                Node* temp=root->right;
                delete root;
                return temp;
            }
            else if (root->right==nullptr){
                Node* temp=root->left;
                delete root;
                return temp;
            }
            //case 03: 2 child
            else{
                root->data=getMax(root->left);
                root->left=deleteBST(root->left, root->data);
            }
        }
        return root;
    }
    public:
    BST(){
        root=nullptr;
    }
    void insert(int data){
        Node* temp=new Node(data, nullptr, nullptr);
        Node* t=root;
        while (t!=nullptr){
            if (data<t->data){
                if (t->left==nullptr){
                    t->left=temp; return;
                }
                t=t->left;
            }
            else{
                if (t->right==nullptr){
                    t->right=temp; return;
                }
                t=t->right;
            }
        }
        root=temp;
    }
    bool search(int data){
        Node* temp=root;
        while (temp!=nullptr){
            if (temp->data==data) return true;
            else if (data<temp->data) temp=temp->left;
            else temp=temp->right;
        }
        return false;
    }
    void traverse(int d=1){
        if (d==1) inOrderTraverse(root);
        else if (d==2) preOrderTraverse(root);
        else postOrderTraverse(root);
        cout<<"\n";
    }
    void remove(int data){
        root=deleteBST(root, data);
    }
};

int main(){
    BST t1;
    t1.insert(5);
    t1.insert(7);
    t1.insert(8);
    t1.insert(6);
    t1.insert(2);
    t1.insert(3);
    t1.insert(1);
    t1.insert(4);
    t1.traverse();
    t1.remove(7);
    t1.remove(1);
    t1.remove(2);
    t1.traverse();
    
}