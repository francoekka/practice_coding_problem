#include<iostream>
using namespace std;

class Complex{
    private:
    int i,j;
    public:
    Complex(){
        i=0;
        j=0;
    }

    Complex(int a, int b){
        i = a;
        j = b;
    }

    void show(){
        cout<<i<<" "<<j<<endl;
    }

    Complex operator +(Complex c){
        Complex temp;
        temp.i = i+c.i;
        temp.j = j+c.j;
        return temp;
    }

};


int main(){
    Complex c1(5,3);
    Complex c2(5,1);
    Complex c;
    c = c1+c2; //output = 10 4 //5+5=10 ... 3+1=4
    c.show();

}