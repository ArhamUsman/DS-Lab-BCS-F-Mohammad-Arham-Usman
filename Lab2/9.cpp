// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Sparse{
    private:
    int** m, row, col;
    
    void input_non_zeros(){
        int r, c, v;
        while (1){
            cout<<"Enter row of non-zero element (-1 to exit): ";
            cin>>r;
            if (r==-1) return;
            if (r>=0&&r<row) break;
            cout<<"Error! Row doesn't exist\n";
        }
        while (1){
            cout<<"Enter col of non-zero element: ";
            cin>>c;
            if (c>=0&&c<col) break;
            cout<<"Error! Column doesn't exist\n";
        }
        cout<<"Enter value: ";
        cin>>m[r][c];
        return input_non_zeros();
    }
    
    public:
    Sparse(){
        cout<<"Enter no of rows: ";
        cin>>row;
        cout<<"Enter no of cols: ";
        cin>>col;
        m=new int*[row];
        for (int i=0; i<row; i++){
            m[i]=new int[col];
            for (int j=0; j<col; j++){
                m[i][j]=0;
            }
        }
        input_non_zeros();
    }
    void display_normal(){
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                    cout<<m[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    void display_compressed(){
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                    if (m[i][j]!=0){
                        cout<<"row: "<<i<<" | col: "<<j<<" | val: "<<m[i][j]<<endl;
                    }
            }
        }
    }
    ~Sparse(){
        for (int i=row-1; i>0; i--){
            delete[] m[i];
        }
        delete[] m;
    }
};


int main() {
    Sparse matrix_A;
    cout<<"\nDisplaying in normal form:\n";
    matrix_A.display_normal();
    cout<<"\nDisplaying in compressed form:\n";
    matrix_A.display_compressed();
    
    return 0;
}