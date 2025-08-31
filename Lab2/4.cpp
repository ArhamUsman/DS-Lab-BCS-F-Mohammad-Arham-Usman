#include <iostream>
#include<conio.h>
using namespace std;

void resize(int*&n, int& size, int& new_size){
    int* temp=new int[new_size];
    for (int i=0; i<size&&i<new_size; i++){
        temp[i]=n[i];
    }
    delete[] n;
    for (int i=0; i<new_size-size; i++){
        cout<<"Enter expense for month "<<size+i<<": ";
        cin>>temp[size+i];
    }
    n=temp;
    size=new_size;
}

void display(int*&n, int &size){
    for (int i=0; i<size; i++){
        cout<<n[i];
        if (i!=size-1) cout<<" | ";
    }
    cout<<endl;
}
int main(){
    int* n, size, total, s;
    string c;
    while (1){
        cout<<"Enter no of months: ";
        cin>>size;
        if (size>=0) break;
        cout<<"Error! Invalid input\n";
    }
    n=new int[size];
    for (int i=0; i<size; i++){
        cout<<"Enter expense for month "<<i<<": ";
        cin>>n[i];
    }
    while (1){
        system("cls");
        cout<<"Press 1 to resize array\nPress 2 to get total expenses\nPress 3 to get average expenses\nPress 4 to view expenses for each month\nPress 5 to exit\n";
        cout<<"\nEnter your choice: ";
        cin>>c;
        system("cls");
        if (c.length()>1){
            cout<<"Error! Invalid choice\n";
        }
        else{
        switch (c[0]){
            case '1':
                while (1){
                    cout<<"Enter new size: ";
                    cin>>s;
                    if (s>size) break;
                    cout<<"Error! New Size should be greater than the previous size\n";
                }
                resize(n, size, s);
                break;
            case '2':
                total=0;
                for (int i=0; i<size; i++){
                    total+=n[i];
                }
                cout<<"Total expenses for all months are "<<total<<".\n";
                break;
            case '3':
                total=0;
                for (int i=0; i<size; i++){
                    total+=n[i];
                }
                cout<<"Average expenses for each month are "<<total/size<<".\n";
                break;         
            case '4':
                display(n, size);
                break;
            case '5':
                delete[] n;
                return 0;
            default:
                cout<<"Error! Invalid choice";
        }
        }
        cout<<"Press any key to continue...";
        _getch();
    }
}