#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d, Node* l=nullptr, Node* r=nullptr){
        data=d;
        left=l;
        right=r;
    }
};


class BST{
    public:
    Node* root;
    bool is_BST(Node* temp){
        if (temp==nullptr) return true;
        if (temp->left==nullptr&&temp->right==nullptr) return true;
        if (temp->left==nullptr){
            if (temp->right->data>temp->data){
                return true&&is_BST(temp->right);
            }
            return false;
        }
        if (temp->right==nullptr){
            if (temp->left->data<temp->data){
                return true&&is_BST(temp->left);
            }
            return false;
        }
        if ((temp->right->data>temp->data)&&(temp->left->data<temp->data)){
            return true&&is_BST(temp->left)&&is_BST(temp->right);
        }
        return false;
    }

};

int main(){
    BST bst;
    bst.root=new Node(10);
    bst.root->left=new Node(5); 
    bst.root->right=new Node(20);
    bst.root->right->left=new Node(25);
    bst.root->right->right=new Node(30);
    if (bst.is_BST(bst.root)){
        cout<<"Yes! Tree is BST\n";
    }
    else{
        cout<<"No! Tree is not BST\n";
    }
}   