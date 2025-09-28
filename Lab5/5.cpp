// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class suduko{
    int** m, size;
    
    bool isSafe(int**& board, int row, int col, int num){
        for (int i=0; i<size; i++){
            if (board[row][i]==num) return false;
        }
        for (int i=0; i<size; i++){
            if (board[i][col]==num) return false;
        }
        int start_row=row-row%3;
        int start_col=col-col%3;
        for (int i=0; i< 3; i++){
            for (int j=0; j<3; j++){
                if (board[i+start_row][j+start_col]==num) return false;
            }
        }
        return true;
    }
    bool findEmpty(int**& board, int&i, int&j){
        for (i=0; i<size; i++){
            for (j=0; j<size; j++){
                if (board[i][j]==0) return true;
            }
        }
        return false;
    }
    bool solve(int **& board){
        int row, col;
        if (!findEmpty(board, row, col)) return true;
        
        for (int num=1; num<=9; num++){
            if (isSafe(board, row, col, num)){
                board[row][col]=num;
                if (solve(board)){
                    return true;    
                }
                board[row][col]=0;
            }
        }
        return false;
    }
    
    public:
    suduko(){
        size=9;
        m=new int*[size];
        for (int i=0; i<size; i++){
            m[i]=new int[size];
            for (int j=0; j<size; j++){
                m[i][j]=0;
            }
        }
        load_default();
    }
    suduko(int s){
        size=9;
        m=new int*[size];
        for (int i=0; i<size; i++){
            m[i]=new int[size];
            for (int j=0; j<size; j++){
                while(1){
                    cout<<"Row: "<<i<<", Col: "<< j<<", Enter a num between 0-9 inclusive: ";
                    cin>>m[i][j];
                    if (m[i][j]>=0&&m[i][j]<=9) break;
                }
            }
        }
    }
    void load_default(){
        int board[9][9] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
        };
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                m[i][j]=board[i][j];
            }
        }
    }
    void displayBoard(){
        if (size<=0) {
            cout<<"Error! Create a sukudo first\n"; return;
        }
        cout<<"Displaying Board\n";
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                cout<<" "<<m[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void solve(){
        cout<<"Solving the board\n";
        if (size<=0) {
            cout<<"Error! Create a board first\n"; return;
        }
        if (!solve(m)){
            cout<<"Error! Cannot Solve the board\n";
            return;
        }
        displayBoard();
    }
    suduko& operator=(suduko& s1){
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                m[i][j]=s1.m[i][j];
            }
        }
        return *this;
    }
    ~suduko(){
        if (m!=nullptr){
            for (int i=0; i<size; i++){
                delete[] m[i];
            }
            delete[] m;
        }
    }
};

int main() {
    string c;
    cout<<"Press 1 to initialise default suduko\nPress 2 to enter custom suduku\nEnter your choice: ";
    cin>>c;
    suduko s1;
    if (c[0]=='2'){
        suduko s2(1);
        s1=s2;
    }
    cout<<"Displaying unsolved board\n";
    s1.displayBoard();
    s1.solve();
    return 0;
}
