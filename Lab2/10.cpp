// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void search(int& row, int*& col, int**& arr, int& id){
    for (int i=0; i<row; i++){
        for (int j=0; j<col[i]; j++){
            if (id==arr[i][j]){
                cout<<"Book found in Category "<<i<<" column "<< j<<endl;
                return;
            }
        }
    }
    cout<<"Book not found\n";
}

int main() {
    int row, **arr, *col;
    while (1){
        cout<<"Enter no of Categories: ";
        cin>>row;
        if (row>=0) break;
        cout<<"Error! Invalid Input"<<endl;
    }
    arr=new int*[row];
    col=new int(row);
    for (int i=0; i<row; i++){
        while (1){
            cout<<"Enter no of Books in Category "<<i<<" : ";
            cin>>col[i];
            if (col[i]>=0) break;
            cout<<"Error! Invalid Input"<<endl;
        }
        arr[i] = new int(col[i]);
        for (int j=0; j<col[i]; j++){
            cout<<"Enter integer ID of Book "<<i<<" in Category "<<j<<": ";
            cin>>arr[i][j];
        }
    }
    cout<<"\nSearching for books:\n";
    while (1){
        int id;
        cout<<"Enter Book ID(int) (-1 to exit): ";
        cin>>id;
        if (id==-1) break;
        search(row, col, arr, id);
    }
    for (int i=row-1; i>=0; i--){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}