#include <iostream>
using namespace std;

class BankAccount{
private:
    int balance;    
public:
    BankAccount(int balance=0){
        this->balance=balance;
    }
    BankAccount(const BankAccount& b1){
        balance=b1.balance;
    }
    bool withdraw(int amount){
        if (balance>=amount){
            balance-=amount;
            return true;
        }
        return false;
    }
    void display(){
        cout<<"Balance: "<<balance<<endl;
    }
};
int main() {
    BankAccount b1, b2(1000), b3(b2);
    cout<<"Account 1:\n";
    b1.display();
    cout<<"Account 2:\n";
    b2.display();
    b3.withdraw(200);
    cout<<"Account 3 (after withdraw):\n";
    b3.display();
    cout<<"Account 2 (after withdraw from account 3):\n";
    b2.display();
    
    return 0;
}
