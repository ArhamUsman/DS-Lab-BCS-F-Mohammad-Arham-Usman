// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int sumTail(int n, int total){
    if (n<=0){
        return total;
    }
    return sumTail(n-1, total+n);
}

int sumNonTail(int n){
    if (n==0||n==1) return n;
    int total=sumNonTail(n-1);
    return total+n;
}

int main() {
    int n;
    cout<<"Enter int (>=1): ";
    cin>>n;
    if (n<1) cout<<"Error\n";
    else {
        cout<<"Total (using tail recursion): "<<sumTail(n, 0);
        cout<<"\nTotal (using non-tail recursion): "<<sumNonTail(n);
    }
    /*
    Tail Recursion is more memory efficient as compiler can optimise it into iterative loop because there is no need to keep previous function calls on stack
    Non Tail recusion calculates total after the recusive call so n needs to be preserved for each function call on the call stack. this can get very memory inefficient specially when n is too large
    */
    return 0;
}
