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
    void add(int x){
        h.push_back(x);
        heapify_upward(h.size()-1);
    }
    int max(int k=1){
        int x=-1;
        for (int i=0; i<k&&!h.empty(); i++){
            x=deletee();
        }
        return x;
    }
};

int main(){
    int x, k; heap arr;
    while (1){
        cout<<"Enter an element(-1 to exit): ";
        cin>>x;
        if (x==-1) break;
        arr.add(x);
    }
    cout<<"Enter k: ";
    cin>>k;
    if (k<1) cout<<"Invalid k";
    else cout<<"Answer: "<<arr.max(k);
}