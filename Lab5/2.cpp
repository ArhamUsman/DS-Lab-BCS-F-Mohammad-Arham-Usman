// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void printNumbers(int n){
    if (n>=1){
        cout<<n<<endl;
        printNumbers(n-1);
    }
    
}

void functionB(int);

void functionA(int n){
    if (n>=1){
        functionB(n-1);
        cout<<"A: "<<n<<endl;
    }
}

void functionB(int n){
    if (n>=1){
        functionA(n-1);
        cout<<"B: "<<n<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter int (>=1): ";
    cin>>n;
    if (n<1) cout<<"Error\n";
    else {
        cout<<"Direct Recursion: \n";
        printNumbers(n);
        cout<<"Indirect Recursion (print number in specific pattern): \n";
        functionA(n);
    }
    return 0;
}