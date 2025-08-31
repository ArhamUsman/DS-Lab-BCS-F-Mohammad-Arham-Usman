// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


int main() {
    int row, **arr, col;
    while (1){
        cout<<"Enter no of days: ";
        cin>>row;
        if (row>=0) break;
        cout<<"Error! Invalid Input"<<endl;
    }
    arr=new int*[row];
    while (1){
        cout<<"Enter no of reading in each day: ";
        cin>>col;
        if (col>=0) break;
        cout<<"Error! Invalid Input"<<endl;
    }
    for (int i=0; i<row; i++){
        arr[i] = new int(col);
        for (int j=0; j<col; j++){
            cout<<"Enter temp reading for day "<<i<<" and "<<j<<" time: ";
            cin>>arr[i][j];
        }
    }
    cout<<"\nCalculating average daily temperature: \n";
    int hot=-1000, cold=1000, cd=-1, hd=-1;
    for (int i=0; i<row; i++){
        int total=0;
        for (int j=0; j<col; j++){
            total+=arr[i][j];
        }
        cout<<"Average temp of day "<<i<<": "<<total/col<<endl;
        if (total/col>hot) {
            hot=total/col; hd=i;
        }
        if (total/col<cold) {
            cold=total/col; cd=i;
        }
    }
    cout<<"Hottest Day is: Day "<< hd<<endl;
    cout<<"Coldest Day is: Day "<< cd<<endl;
    for (int i=row-1; i>=0; i--){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}