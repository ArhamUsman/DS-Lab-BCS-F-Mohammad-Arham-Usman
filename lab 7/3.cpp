#include <iostream>
#include <vector>
using namespace std;

class runner{
    public:
    string name;
    int time;
    runner(string n="", int t=-1){
        name=n; time=t;
    }
    bool operator<(runner &r){
        return time<r.time;
    }
};

void merge(vector<runner>& arr, int l, int m, int r){
    int s1=m-l+1;
    int s2=r-m;
    runner ll[s1], rl[s2];
    for (int i=0; i<s1; i++){
        ll[i]=arr[l+i];
    }
    for (int i=0; i<s2; i++){
        rl[i]=arr[m+1+i];
    }
    int i=0, j=0, k=l;
    while (i<s1&&j<s2){
        if (ll[i]<rl[j]) arr[k++]=ll[i++];
        else arr[k++]=rl[j++];
    }
    while (i<s1) arr[k++]=ll[i++];
    while (j<s2) arr[k++]=rl[j++];
}

void mergeSort(vector<runner>& arr, int l, int r){
    if (l<r){
        int m=l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


int main(){
    vector<runner> arr; int x; string s;
    for (int i=0; i<10; i++){
        cout<<"Enter name for runner 1: ";
        cin>>s;
        cout<<"Enter time: ";
        cin>>x;
        arr.push_back(runner(s, x));
    }
    mergeSort(arr, 0, arr.size()-1);
    cout<<"Top 5 fastest runners:\n";
    int i=0;
    while(i<arr.size()&&i<5){
        cout<<i<<". "<<arr[i].name<<" - "<<arr[i].time<<endl;
        i++;

    }
}