#include <iostream>
using namespace std;

class Box{
private:
    int *height, *width, *length; //height is shallow copied and remaining are deep copied
public:
    Box(int height=0, int width=0, int length=0){
        this->height=new int;
        this->length=new int;
        this->width=new int;
        *(this->height)=height;
        *(this->length)=length;
        *(this->width)=width;
    }
    Box(const Box& b1){                 //Copy Constructor
        this->length=new int;
        this->width=new int;
        this->height=b1.height;         //shallow copy
        *(this->length)=*b1.length;     //deep copy
        *(this->width)=*b1.width;       //deep copy
    }
    void operator=(const Box& b1){      //Copy Assignment Operator
        this->height=b1.height;         //shallow copy
        *(this->length)=*b1.length;     //deep copy
        *(this->width)=*b1.width;       //deep copy
    }
    void change_dimension(int height=0, int width=0, int length=0){
        *(this->height)=height;
        *(this->length)=length;
        *(this->width)=width;
    }
    void display(){
        cout<<"Width: "<<*width<<" Height: "<<*height<<" Length: "<<*length<<endl;
    }
    ~Box(){                             //destructor
        //to avoid double free, use if condition
        if (length!=nullptr) delete length;
        //if (height!=nullptr) delete height;
        //donot delete height as it is shallow copied otherwise double free error
        if (width!=nullptr) delete width;
    }
};

int main(){
    Box b1(10, 10, 10), b2(b1), b3;
    b3=b2;
    cout<<"Initial: \n\n";
    cout<<"Box 1: "<<endl;
    b1.display();
    cout<<"Box 2: "<<endl;
    b2.display();
    cout<<"Box 3: "<<endl;
    b3.display();
    b1.change_dimension(15, 15, 15);
    cout<<"\nAfter Change dimensions of Box 1: \n\n";
    cout<<"Box 1: "<<endl;
    b1.display();
    cout<<"Box 2: "<<endl;
    b2.display();
    cout<<"Box 3: "<<endl;
    b3.display();
    cout<<"\n\nAs Height is shallow copied, it changes for all three boxes.\n";
    cout<<"Length and Width are deep copied so it is independent for Box 2 and Box 3.";
    //It is showing double free error because only one memory is allocated for all 3 height pointers
}
