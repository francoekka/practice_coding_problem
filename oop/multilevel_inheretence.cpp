#include<iostream>
using namespace std;

class A{
    private:
    int i;
    public:

    void setA(int a){
        i=a;
    }
    
    void getA(){
        cout<<i<<" ";
    }

};

class B: public A{
    private:
    int j;
    public:

    void setB(int a,int b){
        setA(a);
        j=b;
    }
    
    void getB(){
        getA();
        cout<<j<<" ";
    }

};

class C: public B{
    private:
    int k;
    public:
    void setC(int a,int b,int c){
        setB(a,b);
        k=c;
    }

    void getC(){
        getB();
        cout<<k<<" ";
    }
};

int main(){
    C c1;
    c1.setC(10,20,30);
    c1.getC();

}