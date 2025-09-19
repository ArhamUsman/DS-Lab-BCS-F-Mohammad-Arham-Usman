// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int calculateFactorial(int n){
    if (n<0) return -1;
    if (n==0||n==1) return 1;
    return calculateFactorial(n-1)*n;
}

int main() {
    int n;
    cout<<"Enter int: ";
    cin>>n;
    if (n<0) cout<<"Error\n";
    else cout<<"Fctorial "<<n<<": "<<calculateFactorial(n);
    return 0;
}