#include<iostream>

void red(int n){
    static int rev=0;
    if(n%10==n){
        rev= rev*10+n;
        std::cout<<rev<<std::endl;
        return;
    }
    rev *= 10; 
    rev += n%10;
    red(n/10);
}

int main(){
    int n;
    std::cin>>n;
    red(n);
    return 0;
}