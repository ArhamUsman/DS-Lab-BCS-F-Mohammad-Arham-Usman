// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class Sorting_Searching{
    int* arr=nullptr, size=0;
    void push_back(int a){
        if (arr==nullptr){
            arr=new int[1];
            arr[0]=a;
            size=1;
        }
        else{
            int* temp=new int[size+1];
            for (int i=0; i<size; i++){
                temp[i]=arr[i];
            }
            temp[size++]=a;
            delete[] arr;
            arr=temp;
        }
    }
    public:
    Sorting_Searching(){
        int x;
        while (1){
            cout<<"Enter an integer (-1 to exit): ";
            cin>>x;
            if (x==-1) break;
            push_back(x);
        }
    }
    int linear_search(int target){
        for (int i=0; i<size; i++){
            if (target==arr[i]) return i;
        }
        return -1;
    }
    void display(){
        if (size==0){
            cout<<"Array is empty";
        }
        for (int i=0; i<size; i++){
            cout<<arr[i];
            if (i!=size-1) cout<<" | "; 
        }
        cout<<endl;
    }
    ~Sorting_Searching(){
        delete[] arr;
    }
};

int main(){
    Sorting_Searching s1;
    cout<<"\nDisplaying array:\n";
    s1.display();
    cout<<"\nEnter a value to find: ";
    int target;
    cin>>target;
    target = s1.linear_search(target);
    if (target==-1){
        cout<<"\nTarget not found\n";
    }
    else{
        cout<<"\nTarget found at index: "<<target<<endl;
    }
}