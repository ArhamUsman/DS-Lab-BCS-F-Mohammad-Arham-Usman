#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d, Node* n){
        data=d; next=n;
    }
};

void addToBucket(Node*& head, int d){
    Node* temp=new Node(d, nullptr);
    Node* curr=head;
    if (head==nullptr) head=temp;
    else{
        while (curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=temp;
    }
}

void clearBucket(Node*& head){
    Node* temp=head;
    while (head!=nullptr){
        temp=head->next;
        delete head;
        head=temp;
    }
}

int getMax(vector<int>& arr){
    if (arr.empty()) return 0;
    int m=arr[0];
    for (int i=1; i<arr.size(); i++){
        if (m<arr[i]) m=arr[i];
    }
    return m;
}

void radixSortAsc(vector<int>& arr){
    int m=getMax(arr);
    Node* buckets[10];
    int exp=1;
    while (m/exp>0){
        //initialise buckets
        for (int i=0; i<10; i++){
            buckets[i]=nullptr;
        }

        //add to buckets
        for (int i=0; i<arr.size(); i++){
            int digit=(arr[i]/exp)%10;
            addToBucket(buckets[digit], arr[i]);
        }

        //collect from bucket
        int k=0;
        for (int i=0; i<10; i++){
            Node* temp = buckets[i];
            while (temp!=nullptr){
                arr[k++]=temp->data;
                temp=temp->next;
            }
            clearBucket(buckets[i]);
        }

        //mov to next digit
        exp*=10;
    }
}

void radixSortDesc(vector<int>& arr){
    int m=getMax(arr);
Node* buckets[10];
int exp=1;
while (m/exp>0){
    //initialise buckets
    for (int i=0; i<10; i++){
        buckets[i]=nullptr;
    }

    //add to buckets
    for (int i=0; i<arr.size(); i++){
        int digit=(arr[i]/exp)%10;
        addToBucket(buckets[digit], arr[i]);
    }

    //collect from bucket
    int k=0;
    for (int i=9; i>=0; i--){
        Node* temp = buckets[i];
        while (temp!=nullptr){
            arr[k++]=temp->data;
            temp=temp->next;
        }
        clearBucket(buckets[i]);
    }

    //mov to next digit
    exp*=10;
    }
}
void display(vector<int>& arr){
    cout<<"\n";
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}

int main(){
    vector<int> arr={36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
    radixSortAsc(arr);
    cout<<"Ascending order:";
    display(arr);
    radixSortDesc(arr);
    cout<<"Descending order:";
    display(arr);
}