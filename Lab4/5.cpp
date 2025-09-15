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
    void insertion_sort(){
        int j, key;
        for (int i=1; i<size; i++){
            key=arr[i];
            j=i-1;
            while (j>=0&&key<arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }
    int interpolation_search(int target){
        int l=0, r=size-1, m;
        while (l<=r && arr[l]<=target&&arr[r]>=target){
            if (arr[l]==arr[r]){
                if (arr[l]==target) return l;
                else return -1;
            }
            m=l+double((r-l)/(arr[l]-arr[r]))*(target-arr[l]);
            if (arr[m]==target) return m;
            else if (arr[m]<target) l=m+1;
            else r=m-1;
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
    s1.insertion_sort();
    cout<<"\nEnter a value to search: ";
    int x;
    cin>> x;
    x=s1.interpolation_search(x);
    if (x!=-1){
        cout<<"\nValue found at index: "<<x<<endl;;
    }
    else{
        cout<<"\nValue not found\n";
    }
    cout<<"\nDisplaying sorted array:\n";
    s1.display();
    
}