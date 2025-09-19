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
        cout<<"\nTotal (using non-tail recursion): "<<sumTail(n, 0);
    }
    return 0;
}