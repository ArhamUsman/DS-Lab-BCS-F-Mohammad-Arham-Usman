// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int row, **arr, *col;
    while (1){
        cout<<"Enter no of Departments: ";
        cin>>row;
        if (row>=0) break;
        cout<<"Error! Invalid Input"<<endl;
    }
    arr=new int*[row];
    col=new int(row);
    for (int i=0; i<row; i++){
        while (1){
            cout<<"Enter no of Employees in Department "<<i<<" : ";
            cin>>col[i];
            if (col[i]>=0) break;
            cout<<"Error! Invalid Input"<<endl;
        }
        arr[i] = new int(col[i]);
        for (int j=0; j<col[i]; j++){
            cout<<"Enter salary of Employee "<<i<<" in Department "<<j<<": ";
            cin>>arr[i][j];
        }
    }
    int d_max=0, d=-1;
    cout<<"\n\nPrinting highest salary in each department:\n";
    for (int i=0; i<row; i++){
        int max=0, total=0;
        for (int j=0; j<col[i]; j++){
            total+=arr[i][j];
            if (max<arr[i][j]) max=arr[i][j];
        }
        cout<<"Department "<<i<<": "<<max<<endl;
        if (total/col[i]>d_max){
            d_max=total/col[i]; d=i;
        }
    }
    cout<<"\nDepartment with overall max average salary: "<<d<<endl;
    for (int i=row-1; i>=0; i--){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}