#include <iostream>
using namespace std;

class Exam{
private:
    string student_name, exam_date;
    int* score;
public:
    Exam(string stu_name="", string ex_date="", int scr=0){
        score=new int;
        student_name=stu_name;
        exam_date=ex_date;
        *score=scr;
    }
    void display(){
        cout<<"Student Name: "<<student_name <<endl;
        cout<<"Exam Date: "<<exam_date <<endl;
        cout<<"Score: "<<*score <<endl;
    }
    void update_score(int scr){
        *score=scr;
    }
};
int main() {
    Exam s1("Ali", "08/23/2025", 80), s2(s1), s3;
    s3=s1;
    cout<<"Before updating s1: "<<endl;
    s1.display();
    s2.display();
    s3.display();
    
    s1.update_score(100);
    
    cout<<"\nAfter updating s1: "<<endl;
    s1.display(); 
    s2.display();
    s3.display();
    
    //Observation:
    //Updating one student record changes the records of other students too
    return 0;
}
