#include <iostream>
using namespace std;


int max_heap[]={8, 7, 6, 5, 4};
int sizee=5;

int get_parent(int i){
    return (i-1)/2;
}
int get_left(int i){
    return 2*i+1;
}
int get_right(int i){
    return 2*i+2;
}
void heapify_upward(int i){
    int p=get_parent(i);
    while (i!=0&&max_heap[p]<max_heap[i]){
        swap(max_heap[p],max_heap[i]);
        i=p; p=get_parent(i);
    }
}
void heapify_downward(int p){
    int l=get_left(p), r=get_right(p), m=p;
    if (l>=sizee&&r>=sizee) return;
    if (l<sizee&&max_heap[l]>max_heap[m]){
        m=l;
    }
    if (r<sizee&&max_heap[r]>max_heap[m]){
        m=r;
    }
    if (m!=p){
        swap(max_heap[p],max_heap[m]);
        heapify_downward(m);
    }
}
void update_key(int i, int val){
    max_heap[i]=val;
    heapify_upward(i);
    heapify_downward(i);
}
int deletee(){
    int temp=max_heap[0];
    max_heap[0]=max_heap[sizee-1];
    sizee--;
    heapify_downward(0);
    return temp;
}

int main(){
    update_key(1, 3);
    for (int i=0; i<sizee; i++){
        cout<<max_heap[i]<<endl;
    }
    cout<<"Deleted: " <<deletee()<<endl;
    for (int i=0; i<sizee; i++){
        cout<<max_heap[i]<<endl;
    }
}

