// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int row, **arr, *col;
    while (1){
        cout<<"Enter no of Students: ";
        cin>>row;
        if (row>=0) break;
        cout<<"Error! Invalid Input"<<endl;
    }
    arr=new int*[row];
    col=new int(row);
    for (int i=0; i<row; i++){
        while (1){
            cout<<"Enter no of Courses of Student "<<i<<" : ";
            cin>>col[i];
            if (col[i]>=0) break;
            cout<<"Error! Invalid Input"<<endl;
        }
        arr[i] = new int(col[i]);
        for (int j=0; j<col[i]; j++){
            cout<<"Enter marks of Student "<<i<<" in Course "<<j<<": ";
            cin>>arr[i][j];
        }
    }
    cout<<"\n\nPrinting each students average marks:\n";
    for (int i=0; i<row; i++){
        int total=0;
        for (int j=0; j<col[i]; j++){
            total+=arr[i][j];
        }
        cout<<"Student "<<i<<": "<<total/col[i]<<endl;
    }
    for (int i=row-1; i>=0; i--){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}