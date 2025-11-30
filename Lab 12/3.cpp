#include <iostream>
#include <vector>
using namespace std;

void intialise_jump_table(){

}

int calculate_jump(){
    
}

vector<int> boyer_moore(string s1, string s2){
    int n=s1.size(), n2=s2.size(), count=0;
    bool found=false;
    vector<int> index;
    int i=0, j=0, k1, k2;
    while (i<n-n2){
        j=0;
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
    string s1="ACGTACGTGACG", s2= "ACG";
    vector<int> result=boyer_moore(s1, s2);
    for (const auto& s: result){
        cout<<s<<endl;
    }
}
