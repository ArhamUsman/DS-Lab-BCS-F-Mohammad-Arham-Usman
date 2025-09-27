// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class maze{
    int** m, size;
    bool isSafe(int** arr, int x, int y, int** sol){
        return (x>=0 && y>=0 && x<size && y<size && arr[x][y]==0 && sol[x][y]==0);
    }
    
    bool ratinMaze(int**& arr, int x, int y, int**& sol){
        if (x==size-1 && y==size-1){
            sol[x][y]=1;
            return true;
        }
        if (isSafe(arr, x, y, sol)){
            sol[x][y]=1;
            if (ratinMaze(arr, x+1, y, sol)){ //down
                return true;
            }
            if (ratinMaze(arr, x-1, y, sol)){ //up
                return true;
            }
            if (ratinMaze(arr, x, y+1, sol)){ //right
                return true;
            }
            if (ratinMaze(arr, x, y-1, sol)){ //left
                return true;
            }
            
            sol[x][y]=0; //backtracking
            return false;
        }
        return false;
    }

    public:
    maze(int n=0){
        m=nullptr; size=0;
        if (n>0) create_maze(n);
    }
    void create_maze(int n){
        srand(time(0));
        int r=rand()%2;
        if (n<=0){
            cout<<"Error! Size should be greater than zero\n";
            return;
        }
        if (size!=0){ //delete old maze
            for (int i=0; i<size; i++){
                delete[] m[i];
            }
            delete[] m;
        }
        size=n;
        m= new int*[size];
        for (int i=0; i<size; i++){
            m[i]=new int[size];
            for (int j=0; j<size; j++){
                if ((i==0&&j==0)||(i==size-1&&j==size-1)){
                    m[i][j]=0;
                }
                else{
                    m[i][j]=r;
                    r=rand()%2;
                }
            }
        }
    }
    void showMaze(){
        if (size<=0) {
            cout<<"Error! Create a maze first\n"; return;
        }
        cout<<"Displaying Maze\n";
        cout<<"Key: - represent empty path, | represent blocked path, R represent Rat, D represent destination\n";
            for (int i=0; i<size; i++){
                for (int j=0; j<size; j++){
                    if (i==0&&j==0){
                        cout<<" R ";
                    }
                    else if (i==size-1&&j==size-1){
                        cout<< " D ";
                    }
                    else if (m[i][j]==0) cout<<" - ";
                    else cout <<" | ";
                }
                cout<<endl;
            }
            cout<<endl;
    }
    void showSol(){
        if (size<=0) {
            cout<<"Error! Create a maze first\n"; return;
        }
        cout<<"Displaying Solution\n";
        int** arr=new int*[size];
        
        for (int i=0; i<size; i++){
            arr[i]=new int[size];
            for (int j=0; j<size; j++){
                arr[i][j]=0;
            }
        }
        
        if (ratinMaze(m, 0, 0, arr)){
            cout<<"Key: 1 represent the rat's path\n";
            for (int i=0; i<size; i++){
                for (int j=0; j<size; j++){
                    if (arr[i][j]==1) cout<<" 1 ";
                    else cout << " - ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        else{
            cout<<"Error! Rat is unable to escape the maze\n";
        }
        
        for (int i=0; i<size; i++){
            delete[] arr[i];
        }
        delete[] arr;
    }
    ~maze(){
        if (m!=nullptr){
            for (int i=0; i<size; i++){
                delete[] m[i];
            }
            delete[] m;
        }
    }
};

int main() {
    maze m1(4);
    m1.showMaze();
    m1.showSol();
    return 0;
}
