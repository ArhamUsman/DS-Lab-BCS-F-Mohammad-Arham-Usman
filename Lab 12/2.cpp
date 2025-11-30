#include <iostream>
#include <vector>
using namespace std;

int hashing(string& s1, int b, int s){
    int x=0, j=2;
    if (b+s>s1.size()) return -1;
    for (int i=b; i<b+s; i++){
        x=x+(s1[i]*j);
        j*=2;
    }
    return x%93;
}

vector<int> rabin_karp(string s1, string s2){
    int n=s1.size(), n2=s2.size(), count=0;
    bool found=false;
    vector<int> index;
    int i=0, j=0, k1, k2;
    k2=hashing(s2, 0, n2);
    while (i<n-n2){
        j=0;
        k1=hashing(s1, i, n2);
        if (k1==k2){
            count++;
            found=true;
            while (j<n2){
                if (s1[i]==s2[j]){
                    i++; j++;
                }
                else {
                    found=false; break;
                }
            }
            i-=j;
            if (found){
                count--;
                index.push_back(i);
            }
        }
        i++;
    }
    cout<<"No of false positive hash matches: "<<count<<endl;
    return index;
}

int main(){
    string s1="Data structures and algorithms are fun. Algorithms make tasks easier.", s2= "Algorithms";
    vector<int> result=rabin_karp(s1, s2);
    for (const auto& s: result){
        cout<<s<<endl;
    }
}
