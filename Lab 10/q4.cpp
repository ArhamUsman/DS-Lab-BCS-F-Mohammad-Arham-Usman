#include <iostream>
#include <vector>
using namespace std;

class heap{
    vector<int> h;
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
        while (i!=0&&h[p]<h[i]){
            swap(h[p],h[i]);
            i=p; p=get_parent(i);
        }
    }
    void heapify_downward(int p){
        int l=get_left(p), r=get_right(p), m=p;
        if (l>=h.size()&&r>=h.size()) return;
        if (l<h.size()&&h[l]>h[m]){
            m=l;
        }
        if (r<h.size()&&h[r]>h[m]){
            m=r;
        }
        if (m!=p){
            swap(h[p],h[m]);
            heapify_downward(m);
        }
    }
    int deletee(){
        if (h.empty()) return -1;
        int temp=h[0];
        h[0]=h.back();
        h.pop_back();
        heapify_downward(0);
        return temp;
    }
    public:
    heap(){}
    heap(vector<int>& a){
        for (const auto& s:a){
            add(s);
        }
    }
    void add(int x){
        h.push_back(x);
        heapify_upward(h.size()-1);
    }
    vector<int> get_heap(){
        return h;
    }
};

int main(){
    int x, k; vector<int> arr;
    while (1){
        cout<<"Enter an element(-1 to exit): ";
        cin>>x;
        if (x==-1) break;
        arr.push_back(x);
    }
    heap a(arr);
    arr=a.get_heap();
    cout<<"Max heap: \n";
    for (const auto&s: arr){
        cout<<s<<endl;
    }
}