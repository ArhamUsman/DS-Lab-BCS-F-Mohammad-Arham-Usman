// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int size, *arr, temp, temp2;
    cout<<"Enter size: ";
    cin>>size;
    arr=new int(size);
    for (int i=0; i<size; i++){
        arr[i]=0;
    }
    cout<<"\nUpdating array!!!"<<endl;
    while (1){
        cout<<"Enter index (-1 to exit): ";
        cin>>temp;
        if (temp==-1) break;
        if (temp<0||temp>=size){
            cout<<"Index out of bounds!"<<endl;
            continue;
        }
        cout<<"Enter new value: ";
        cin>>temp2;
        arr[temp]=temp2;
    }
    cout<<"\n\nPrinting array:\n";
    for (int i=0; i<size; i++){
        cout<<arr[i];
        if (i!=size-1) cout<<" | ";
    }
    delete []arr;
    return 0;
}