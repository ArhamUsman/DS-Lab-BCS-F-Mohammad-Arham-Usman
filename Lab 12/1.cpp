Conversation opened. 1 unread message.

Skip to content
Using NUCES-FAST Mail with screen readers

1 of 2,866
Ds
External
Inbox

M. Arham Usman
Attachments
3:33 PM (0 minutes ago)
to me



Kind Regards,
M. Arham Usman

 3 Attachments
  •  Scanned by Gmail



#include <iostream>
#include <vector>
using namespace std;

vector<int> find_substring(string s1, string s2){
    int count=0, n=s1.size(), n2=s2.size();
    bool found=false;
    vector<int> index;
    int i=0, j=0;
    while (i<n-n2+1){
        j=0;
        count++;
        if (s1[i]==s2[j]){
            found=true;
            while (j<n2){
                count++;
                if (s1[i]==s2[j]){
                    i++; j++;
                }
                else {
                    found=false; break;
                }
            }
            i-=j;
            if (found){
                index.push_back(i);
            }
        }
        i++;
    }
    cout<<"No of Comparisons: "<<count<<endl;
    return index;
}

int main(){
    string s1="the quick brown fox jumps over the lazy dog", s2= "dog";
    vector<int> result=find_substring(s1, s2);
    for (const auto& s: result){
        cout<<s<<endl;
    }
}
1.cpp
Displaying 1.cpp.
