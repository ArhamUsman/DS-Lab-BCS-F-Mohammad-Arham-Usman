#include<iostream>
#include<conio.h>
using namespace std;

void display(int**& a, int**& b, int x, int y, int op){
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            if (op==0) cout<<a[i][j]+b[i][j]<<"\t";
            else if (op==1) cout<<a[i][j]-b[i][j]<<"\t";
            else if (op==2) cout<<a[i][j]<<"\t";
            else if (op==3) cout<<b[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int input(string s){
    string temp;
    while(1){
        cout<<"Enter "<<s<<": ";
        cin>>temp;
        if (temp.size()==1&&temp[0]>='0'&&temp[0]<='9') break;
        cout<<"Error! Invalid input\n";
    }
    return temp[0]-'0';
}

void free(int**& a, int rows){
    for (int i=rows-1; i>=0; i--){
        delete[] a[i];
    }
    delete[] a;
}

void enter(int**& a, int x, int y, string s){
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            cout<<"Enter "<<s<<"["<<i<<"]["<<j<<"]: ";
            cin>>a[i][j];
        }
    }
}

int main(){
    int **a, **b, x, y;
    x=input("no of rows");
    y=input("no of cols");
    a=new int*[x];
    b=new int*[x];
    for (int i=0; i<x; i++){
        a[i]=new int[y];
        b[i]=new int[y];
    }
    enter(a, x, y, "a");
    enter(b, x, y, "b");
    cout<<"\nMatrix A: \n";
    display(a, b, x, y, 2);
    cout<<"\nMatrix B: \n";
    display(a, b, x, y, 3);
    cout<<"\nAddition of A and B:\n";
    display(a, b, x, y, 0);
    cout<<"\nSubtraction of A and B:\n";
    display(a, b, x, y, 1);
    free(a, x);
    free(b, x);
}