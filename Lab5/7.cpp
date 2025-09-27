// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class chess{
    int** m, size;
    
    bool isSafe(int*& board, int row, int col){
        for (int i=0; i< row; i++){
            if (board[i]==col||abs(board[i]-col)==abs(i-row)){
                return false;
            } 
        }
        return true;
    }
    
    bool solveNQueens(int *& board, int n, int row=0){
        if (row==n){
            //all queens placed successfully
            return true;
        }
        for (int col=0; col<n; col++){
            if (isSafe(board, row, col)){
                board[row]=col;
                //recursively place in next row
                if (solveNQueens(board, n, row+1)){
                    return true;    //if sol is found
                }
                //if placing queen in this col doesn't lead to a sol, backtrack
                board[row]=-1;
            }
        }
        //if no safe position found, backtrack
        return false;
    }
    
    public:
    chess(int n=8){
        if (n<=0) size=8;
        else size=n;
        m=new int*[size];
        for (int i=0; i<size; i++){
            m[i]=new int[size];
            for (int j=0; j<size; j++){
                m[i][j]=0;
            }
        }
    }
    
    void displayBoard(){
        if (size<=0) {
            cout<<"Error! Create a board first\n"; return;
        }
        cout<<"Displaying Board\n";
        cout<<"Key: - represent empty block, Q represent Queen placed\n";
            for (int i=0; i<size; i++){
                for (int j=0; j<size; j++){
                    if (m[i][j]==0) cout<<" - ";
                    else cout <<" Q ";
                }
                cout<<endl;
            }
            cout<<endl;
    }
    
    void placeQueens(){
        if (size<=0) {
            cout<<"Error! Create a board first\n"; return;
        }
        int* arr=new int[size];
        
        for (int i=0; i<size; i++){
            arr[i]=-1;
        }
        
        if (solveNQueens(arr, size, 0)){
            for (int i=0; i<size; i++){
                m[i][arr[i]]=1;
            }
        }
        else{
            cout<<"Error! Cannot place the Queens\n";
        }
        
        delete[] arr;
    }
    ~chess(){
        if (m!=nullptr){
            for (int i=0; i<size; i++){
                delete[] m[i];
            }
            delete[] m;
        }
    }
};

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    chess c1(n);
    c1.placeQueens();
    c1.displayBoard();
    return 0;
}
