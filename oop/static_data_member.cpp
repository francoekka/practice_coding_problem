/*
In normal situations when we instantiate objects of a class each object gets 
its own copy of all normal member variables. When we declare a member of a class 
as static it means no matter how many objects of the class are created, there is only one 
copy of the static member. This means one single copy of that data member is shared between
all objects of that class. All static data is initialized to zero when the first object is created,
if no other initialization is present. Static data members can be initialized outside 
the class using the scope resolution operator (::) to identify which class it belongs to.
Since Static data members are class level variables, we do not require the object to access
these variables and they can be accessed simply by using the class name and scope resolution(::) 
operator with the variable name to access its value. Also a static data member cannot be private. 
A very common use of static data members is to keep a count of total objects of a particular class 
(program counter kind of application).
*/



/*
By declaring a function member as static, you make it independent of any particular object of the class. 
A static member function can be called even if no objects of the class exist and the static functions are
accessed using only the class name and the scope resolution operator (::).
A static member function can only access static data member, other static member functions and any other 
functions from outside the class.
Static member functions have a class scope and they do not have access to the this pointer of the class.
*/



#include<iostream>
using namespace std;

class Example{
    public:
    static int count; // shared amoung the objects
    Example(){
        count++;
    }

    static int getCount(){
        return count;
    }
};

int Example::count = 0;

int main(){
    Example e1;
    Example e2;
    cout<<e2.count<<endl; //output will be 2

    cout<<Example::getCount()<<endl; //without any object we can access static member function
}