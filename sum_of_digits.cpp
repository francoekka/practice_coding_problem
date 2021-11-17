#include<iostream>

int sod(int n){
    if(n<1){
        return 0;
    }
    static int sum = 0;
    sum += n%10;
    n=n/10;
    sod(n);
    return sum;
}

int main(){
    int n;
    std::cin>>n;
    int result =sod(n);
    std::cout<<result<<std::endl;
}