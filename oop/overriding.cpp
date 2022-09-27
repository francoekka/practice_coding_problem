/*
Connecting the function call to the function body is called Binding. 
When it is done before the program is run, its called Early Binding or 
Static Binding or Compile-time Binding.
*/

#include<iostream>
using namespace std;

class A{
    public:
    void show(){
        cout<<"this is class A"<<endl;
    }
};

class B: public A{
    public:
    void show(){
        cout<<"this is class B"<<endl;
    }
};

class C{
    public:
    virtual void show(){
        cout<<"this is class C"<<endl;
    }
};

class D: public C{
    public:
    void show(){
        cout<<"this is class D"<<endl;
    }
};

int main(){
    A a1;
    B b1;
    a1.show(); //early binding
    b1.show(); //early binding or compile-time polymorphism

    //late binding or dynamic polymorphism
    C *c; //pointer object
    D d;
    c = &d; //pointer pointing to class D's member function
    c->show(); //execute the member function of its base class
}