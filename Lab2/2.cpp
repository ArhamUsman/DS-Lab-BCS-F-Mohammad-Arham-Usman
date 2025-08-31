// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int row, **arr, *col;
    while (1){
        cout<<"Enter no of rows: ";
        cin>>row;
        if (row>=0) break;
        cout<<"Error! Invalid Input"<<endl;
    }
    arr=new int*[row];
    col=new int(row);
    for (int i=0; i<row; i++){
        while (1){
            cout<<"Enter no of cols in row "<<i<<" : ";
            cin>>col[i];
            if (col[i]>=0) break;
            cout<<"Error! Invalid Input"<<endl;
        }
        arr[i] = new int(col[i]);
        for (int j=0; j<col[i]; j++){
            cout<<"Row "<<i<<" Column "<<j<<endl;
            while (1){
                cout<<"Enter 1 if occupied, 0 if empty: ";
                cin>>arr[i][j];
                if (arr[i][j]==0||arr[i][j]==1) break;
                cout<<"Error! Invalid Input"<<endl;
            }
        }
    }
    cout<<"\n\nPrinting array:\n";
    for (int i=0; i<row; i++){
        for (int j=0; j<col[i]; j++){
            cout<<arr[i][j];
            if (j!=col[i]-1) cout<<" | ";
        }
        cout<<endl;
    }
    for (int i=row-1; i>=0; i--){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}