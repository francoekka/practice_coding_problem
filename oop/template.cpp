/*
Templates are the foundation of generic programming, which involves writing code 
in a way that is independent of any particular type. Templates are powerful features 
of C++ which allows you to write generic programs.
*/
#include<iostream>
using namespace std;

//function template
template <typename T>
T Max(T a, T b){
    return a>b ? a:b;
}

//class template
template <class T>
class addition{
    public:
    void addit(T a, T b){
        cout<<a+b<<endl;
    }
};

int main(){

    //function template
    int a = 10;
    int b=3;

    float c = 10.5;
    float d = 11.5;

    string e = "hello";
    string f = "world";

    cout<<Max(a,b)<<endl;
    cout<<Max(c,d)<<endl;
    cout<<Max(e,f)<<endl;

    //class template
    addition <int> x;
    x.addit(1,2);

}
