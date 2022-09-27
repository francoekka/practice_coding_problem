#include<iostream>
using namespace std;

int main(){
    int arr[]={2,4,3,4,3,5,1,2};
    int n=8;
    int res=0;
    for(int i=0;i<n;i++){
        res = res^arr[i];
    }
    //cout<<res<<" res "<<endl;
    int res_check = res;
    int position = 0;
    int one =1;
    while(!(res & one)){
        res = res>>1;
        position++;
    }

    int ans1=0;
    

    for(int i=0;i<n;i++){
        int check = arr[i]>>position;
        if(check&1){
            ans1 = ans1^arr[i];
        }
    }

    int ans2= res_check^ans1;
    
    cout<<ans1<<" "<<ans2<<endl;
     //cout<<even<<" "<<odd;

}