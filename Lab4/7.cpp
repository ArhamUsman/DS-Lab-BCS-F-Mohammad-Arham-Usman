// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

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
    Sorting_Searching(int i){
        srand(time(0));
        arr=new int[i];
        for (int j=0; j<i; j++){
            arr[j]=rand()%i;
        }
        size=i;
    }
    void shell_sort(){
        auto start = high_resolution_clock::now();
        int no_of_comparison=0, no_of_swap=0;
        //start with a big gap, then reduce the gap
        for (int gap=size/2; gap>0; gap/=2){
            // Perform a gapped insertion sort for this gap size
            for (int j=gap; j<size; j++){
                int key=arr[j];
                int res=j;
                //insertion sort with gap-steps
                //res>=gap ensure res-gap>=0 so no seg fault
                //arr[res-gap] is gap-steps behind the curr val
                no_of_comparison++;
                while (res>=gap && arr[res-gap]>key){
                    arr[res] = arr[res-gap];
                    //update res to go back gap-steps
                    res-=gap;
                    no_of_comparison++;
                    no_of_swap++;
                }
                //Put key into its correct position
                arr[res] = key;
            }
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
        cout<<"No of comparisons: "<<no_of_comparison<<endl;
        cout<<"No of swaps: "<<no_of_swap<<endl;
        
    }
    
    void insertion_sort(){
        auto start = high_resolution_clock::now();
        int no_of_comparison=0, no_of_swap=0;
        
        int j, key;
        for (int i=1; i<size; i++){
            key=arr[i];
            j=i-1;
            no_of_comparison++;
            while (j>=0&&key<arr[j]){
                arr[j+1]=arr[j];
                j--;
                no_of_comparison++;
                no_of_swap++;
            }
            arr[j+1]=key;
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
        cout<<"No of comparisons: "<<no_of_comparison<<endl;
        cout<<"No of swaps: "<<no_of_swap<<endl;
        
    }
    
    void bubble_sort(){
        auto start = high_resolution_clock::now();
        int no_of_comparison=0, no_of_swap=0;
        
        for (int i=0; i<size-1; i++){
            for (int j=0; j<size-1; j++){
                no_of_comparison++;
                if (arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    no_of_swap++;
                }
            }
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " microseconds" << endl;
        cout<<"No of comparisons: "<<no_of_comparison<<endl;
        cout<<"No of swaps: "<<no_of_swap<<endl;
        
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
    Sorting_Searching s1(1000), s2(1000), s3(1000);
    cout<<"\nBubble Sort 1000 elements:\n";
    s1.bubble_sort();
    cout<<"\nInsertion Sort 1000 elements:\n";
    s2.insertion_sort();
    cout<<"\nShell Sort 1000 elements:\n";
    s3.shell_sort();
}