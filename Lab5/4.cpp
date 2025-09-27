// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int ackermann(int m, int n){
    if (m==0) {
        cout<<"Returned: "<<n+1<<endl;
        return n+1;
    }
    if (m>0 && n==0) {
        cout<<"Returned: ackermann("<<m-1<<", "<< 1<<")"<<endl;
        return ackermann(m-1, 1);
    }
    if (m>0 && n>0) {
        cout<<"Returned: ackermann("<<m-1<<", ackermann("<<m<<", "<<n-1<<"))"<<endl;
        return ackermann(m-1, ackermann(m, n-1));
    }
    cout<<"Unreachable condition!\n";
    return 0;
}

/*Understanding:
The condition m>0 && n>0 has a return recursive call which has a second recursive call in its parameter. The recursive call in the parameter needs to be completed first before the return recursive call can begin
*/


int main() {
    int m, n, res;
    cout<<"Enter m: ";
    cin>>m;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"ackermann("<<m<<", "<<n<<")\n";
    res=ackermann(m, n);
    cout<<"\n\nAns: "<<res;
    return 0;
}
