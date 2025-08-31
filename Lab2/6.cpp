#include <iostream>
using namespace std;

class SafePointer{
private:
    int* arr, size;
public:
    SafePointer(int size=0, int val=0){
        arr=new int[size];
        this->size=size;
        for (int i=0; i<size; i++) arr[i]=val;
    }
    
    bool setValue(int index, int val){
        if (index<0||index>=size) {
            cout<<"ERROR! Index Out Of Range\n";
            return false;
        }arr[index]=val;
        return true;
    }

    int getValue(int index){
        if (index<0||index>=size) {
            cout<<"ERROR! Index Out Of Range\n";
            return -1;
        }
        return arr[index];
        
    }

    bool release(int index){
        if (index<0||index>=size) {
            return false;
        }
        if (size==1){
            delete arr;
            arr=nullptr;
        }
        int* temp=new int[size-1];
        for (int i=0; i<index; i++) temp[i]=arr[i];
        for (int i=index+1; i<size; i++) temp[i-1]=arr[i];
        delete[] arr;
        arr=temp; size--;
        return true;
    }

    int length(){
        return size;
    }

    ~SafePointer(){
        delete[] arr;
    }
};

int main(){
    SafePointer marks(5);
    marks.setValue(0, 10);
    marks.setValue(1, 30);
    marks.setValue(2, 40);
    marks.setValue(3, 60);
    marks.setValue(4, 100);

    for (int i=0; i<marks.length(); i++){
        cout<<marks.getValue(i);
        if (i!=marks.length()-1) cout<<" | ";
        else cout<<endl;
    }
    int i=0;
    while(marks.release(i--)){}
}
