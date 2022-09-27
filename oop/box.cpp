#include<iostream>
using namespace std;

class Box{
    private:
    int length;
    int breadth;

    public:
    int height;

    void setValues(int l, int b, int h){
        length = l;
        breadth = b;
        height = h;
    }

    void getLength(){       //get length as length is private
        cout<<length<<endl;
    }

    void getBreadth(){
        cout<<breadth<<endl;
    }
};

int main(){
    Box b1;
    b1.setValues(10,20,30);
    b1.getLength();
    b1.getBreadth();
    
    cout<<b1.height<<endl; // it is public so directly we can access

    // cout<<b1.length<<endl; // compiler will throw an error for accessing a private data member outside the class
                            // this is called data hiding.
}