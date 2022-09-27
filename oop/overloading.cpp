/*
Whenever same method name is exiting multiple times in the same class with 
different number of parameter or different order of parameters or different 
types of parameters is known as method overloading.
*/

#include<iostream>
using namespace std;

class A{
    public:
    void add(int a, int b)
    {
        cout<<a+b<<endl;
    }
    void add(int a,int b,int c){
        cout<<a+b+c<<endl;
    }
};

int main(){
    A a1;
    a1.add(10,20);
    a1.add(10,20,30);
}