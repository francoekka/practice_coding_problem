/*
A class constructor is a special member function of a class that is executed 
whenever we create new objects of that class. Every time an instance of a class 
is created the constructor method is called.
The constructor has the same name as the class and it doesn’t return any type(not even void).
Constructors can be very useful for setting initial values for certain member variables.
Constructors can be defined either inside the class definition or outside class definition 
using class name and scope resolution :: operator. A constructor can never be private.
*/

/*
A destructor is a special member function of a class that is executed whenever an object of it’s class
goes out of scope or whenever the delete expression is applied to a pointer to the object of that class.
A destructor will have exact same name as the class prefixed with a tilde (~) and it can neither return 
a value nor can it take any parameters. Destructor can be very useful for releasing resources before coming 
out of the program like closing files, releasing memories etc.
*/

#include<iostream>
using namespace std;

class Box{
    private:
    int item;
    public:
    /*Box(){
        cout<<"constructed called"<<endl;
    }*/

    Box(); //constructor declared 

    ~Box(){     //free up the space
        cout<<"destructor called"<<endl;
    }
};


Box::Box(){         //constructor defined
    cout<<"constructor called outside the class"<<endl;
}

int main(){
    Box b1;
}
