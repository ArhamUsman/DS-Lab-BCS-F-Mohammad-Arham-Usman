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
    void selection_sort(){
        int min, temp;
        for (int i=0; i<size-1; i++){
            min=i;
            for (int j=i+1; j<size; j++){
                if (arr[j]<arr[min]) min=j;
            }
            if (min!=i){
                temp=arr[i];
                arr[i]=arr[min];
                arr[min]=temp;
            }
        }
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
    cout<<"\nDisplaying unsorted array:\n";
    s1.display();
    s1.selection_sort();
    cout<<"\nDisplaying sorted array:\n";
    s1.display();
}