#include <iostream>
#include <vector>
using namespace std;

class Student{
    public:
    string name;
    int score;
    Student(string name="", int score=-1){
        this->name=name;
        this->score=score;
    }
};

class Node{
    public:
    Student data;
    Node* next;
    Node(Student d, Node* n){
        data=d; next=n;
    }
};

void addToBucket(Node*& head, Student d){
    Node* temp=new Node(d, head);
    head=temp;
}

void clearBucket(Node*& head){
    Node* temp=head;
    while (head!=nullptr){
        temp=head->next;
        delete head;
        head=temp;
    }
}

int getMax(vector<Student>& arr){
    if (arr.empty()) 0;
    Student m=arr[0];
    for (int i=1; i<arr.size(); i++){
        if (m.score<arr[i].score) m=arr[i];
    }
    return m.score;
}

void radixSort(vector<Student>& arr){
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
            int digit=(arr[i].score/exp)%10;
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

void display(vector<Student>& arr){
    cout<<"\n";
    for (int i=0; i<arr.size(); i++){
        cout<<arr[i].name<<"\t"<<arr[i].score<<endl;
    }
}

int main(){
    vector<Student> arr; int x; string s;
    while (1){
        cout<<"Enter Student name(-1 to exit): ";
        cin>>s;
        if (s=="-1") break;
        cout<<"Enter Student marks: ";
        cin>>x;
        arr.push_back(Student(s, x));
    }
    radixSort(arr);
    display(arr);
}