#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>
using namespace std;

class Combatant{
    public:
    string name;
    int health;
    int damage;
    Combatant(string n="", int h=0, int d=0){
        name=n;
        health=h;
        damage=d;
    }
    bool operator<(const Combatant& other){
        return health<other.health;
    }
    bool operator==(const Combatant& obj){
        return name==obj.name;
    }
    friend std::ostream& operator<<(std::ostream& os, const Combatant& obj);
};

std::ostream& operator<<(std::ostream& os, const Combatant& obj){
    os<<"Name: "<<obj.name<<" | Health Points: "<<obj.health<<" | Attack Power: "<<obj.damage;
    return os;
}

class Node{
    public:
    Combatant data;
    Node* left;
    Node* right;
    Node(Combatant d, Node* l, Node* r){
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
            cout<<root->data<<"\n";
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
    Combatant getMax(Node* root){
        if (root->right==nullptr) return root->data;
        return getMax(root->right);
    }
    Node* deleteBST(Node*&root, Combatant data){
        if (root==nullptr) return root;
        if (data<root->data) root->left = deleteBST(root->left, data);
        else if (root->data<data) root->right = deleteBST(root->right, data);
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
    Node* getMin(Node* root){
        if (root->left==nullptr) return root;
        return getMin(root->left);
    }
    void remove(Combatant data){
        root=deleteBST(root, data);
    }
    bool search(Combatant data){
        Node* temp=root;
        while (temp!=nullptr){
            if (temp->data==data) return true;
            else if (data<temp->data) temp=temp->left;
            else temp=temp->right;
        }
        return false;
    }
    public:
    BST(){
        root=nullptr;
        srand(static_cast<unsigned int>(time(0)));
    }
    void insert(Combatant data){
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
    
    void display(){
        inOrderTraverse(root);
    }
    int attack(){
        Node* temp=getMin(root);
        int random_no=rand()%4;
        return temp->data.damage+random_no;
    }
    bool take_damage(int n){
        Node* temp=getMin(root);
        temp->data.health-=n;
        if (temp->data.health<=0){
            remove(temp->data);
            if (root==nullptr) return true;
        }
        return false;
    }
    string get_frontLine(){
        Node* temp=getMin(root);
        return temp->data.name;
    }
};

int main(){
    BST player, enemy;
    Combatant   p1("P1", 15, 9), e1("E1", 10, 5),
                p2("P2", 10, 8), e2("E2", 15, 6),
                p3("P3", 20, 7), e3("E3", 20, 7),
                p4("P4", 25, 6), e4("E4", 25, 8),
                p5("P5", 30, 5), e5("E5", 30, 9);
    player.insert(p1);
    player.insert(p2);
    player.insert(p3);
    player.insert(p4);
    player.insert(p5);
    enemy.insert(e1);
    enemy.insert(e2);
    enemy.insert(e3);
    enemy.insert(e4);
    enemy.insert(e5);
    int i=1, x;
    while (1){
        cout<<"___________________\n";
        cout<<"Round "<<i<<":\n";
        cout<<"Start: \n";
        cout<<"Player: \n";
        player.display();
        cout<<"Enemy: \n";
        enemy.display();
        cout<<"---Player is attacking---\n";
        x=player.attack();
        cout<<"Player "<<player.get_frontLine()<<" has attacked enemy "<<enemy.get_frontLine()<<" with damage "<<x<<"\n";
        
        bool ended=enemy.take_damage(x);
        if (ended){
            cout<<"---Player has won---\n";
            break;
        }
        cout<<"Updated Enemy: \n";
        enemy.display();
        cout<<"---Enemy is attacking---\n";
        x=player.attack();
        cout<<"Enemy "<<enemy.get_frontLine()<<" has attacked player "<<player.get_frontLine()<<" with damage "<<x<<"\n";
        ended=player.take_damage(x);
        if (ended){
            cout<<"---Enemy has won---\n";
            break;
        }
        cout<<"Updated Player: \n";
        player.display();
        i++;
    }
}