#include<iostream>
using namespace std;

class A{
    private:
    int i;
    protected:
    int j;
    public:
    int k;
    void setValues(int m,int n){
        i = m;
        j = n;
    }

    int geti(){
        return i;
    }

    int getj(){
        return j;
    }
};

class B: public A{
    public:
    B(){};
};

int main(){
    B b1;
    b1.setValues(2,5);
    cout<<b1.geti()<<endl;
    cout<<b1.getj()<<endl;
    b1.k = 10;
    cout<<b1.k<<endl;
}