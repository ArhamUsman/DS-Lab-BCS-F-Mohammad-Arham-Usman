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
    void comb_sort(){
        int gap=size, no_of_comparisons=0, no_of_swaps=0;
        float shrink_factor=1.3;
        bool swapped=true;
        while (swapped){
            swapped=false;
            gap=gap/shrink_factor;
            for (int i=0; i+gap<size; i++){
                no_of_comparisons++;
                if (arr[i]>arr[i+gap]){
                    int temp;
                    temp=arr[i];
                    arr[i]=arr[i+gap];
                    arr[i+gap]=temp;
                    swapped=true;
                    no_of_swaps++;
                }
            }
        }
        cout<<"\nNo of comparisons: "<<no_of_comparisons<<endl;
        cout<<"No of swaps: "<<no_of_swaps<<endl;
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
    s1.comb_sort();
    cout<<"\nDisplaying sorted array:\n";
    s1.display();
    
}