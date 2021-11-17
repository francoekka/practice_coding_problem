#include<iostream>

//naive method
// int sod(int n){
//     if(n<1){
//         return 0;
//     }
//     static int sum = 0;
//     sum += n%10;
//     n=n/10;
//     sod(n);
//     return sum;
// }

int sod(int n){
    if(n<1)
        return 0;
    return (n%10)+sod(n/10);
}


int main(){
    int n;
    std::cin>>n;
    int result =sod(n);
    std::cout<<result<<std::endl;
}