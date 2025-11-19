#include <iostream>
#include <vector>
using namespace std;

int get_parent(int i){
    return (i-1)/2;
}
int get_left(int i){
    return 2*i+1;
}
int get_right(int i){
    return 2*i+2;
}
bool max_heap(vector<int>& heap){
    int l=0, r=0;
    for (int i=0; l<heap.size()&&r<heap.size(); i++){
        l=get_left(i); r=get_right(i);
        if ((l<heap.size()&&heap[i]<heap[l])||
            (r<heap.size()&&heap[i]<heap[r])){
            return false;
        }
    }
    return true;
}
bool min_heap(vector<int>& heap){
    int l=0, r=0;
    for (int i=0; l<heap.size()&&r<heap.size(); i++){
        l=get_left(i); r=get_right(i);
        if ((l<heap.size()&&heap[i]>heap[l])||
            (r<heap.size()&&heap[i]>heap[r])){
            return false;
        }
    }
    return true;
}
bool is_heap(vector<int>& heap){
    return max_heap(heap)||min_heap(heap);
}
void heapify_upward(vector<int>& max_heap,int i){
    int p=get_parent(i);
    while (i!=0&&max_heap[p]<max_heap[i]){
        swap(max_heap[p],max_heap[i]);
        i=p; p=get_parent(i);
    }
}
void heapify_downward(vector<int>& max_heap,int p){
    int l=get_left(p), r=get_right(p), m=p;
    if (l>=max_heap.size()&&r>=max_heap.size()) return;
    if (l<max_heap.size()&&max_heap[l]>max_heap[m]){
        m=l;
    }
    if (r<max_heap.size()&&max_heap[r]>max_heap[m]){
        m=r;
    }
    if (m!=p){
        swap(max_heap[p],max_heap[m]);
        heapify_downward(max_heap, m);
    }
}
int deletee(vector<int>& max_heap){
    int temp=max_heap[0];
    max_heap[0]=max_heap[max_heap.size()-1];
    max_heap.pop_back();
    heapify_downward(max_heap, 0);
    return temp;
}
void create_max_heap(vector<int>& arr){
    if (max_heap(arr)) return;
    vector<int> heap;
    for (int i=0; i<arr.size(); i++){
        heap.push_back(arr[i]);
        heapify_upward(heap, heap.size()-1);
    }
    arr=heap;
}
void sort(vector<int>& arr){
    create_max_heap(arr);
    vector<int> temp;
    while (arr.size()>0){
        temp.push_back(deletee(arr));
    }
    while (temp.size()>0){
        arr.push_back(temp.back());
        temp.pop_back();
    }
}
int main(){
    vector<int> arr={8, 7, 6, 5, 4};
    cout<<"Is arr heap: ";
    if (is_heap(arr)) cout<<"yes\n";
    else cout<<"no\n";
    cout<<"Sorting in ascending order:\n";
    sort(arr);
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<endl;
    }
}