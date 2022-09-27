// https://www.codechef.com/problems/CRES102#:~:text=You%20are%20given%20an%20iron,has%20occured%20in%20that%20building.

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& v){
    
    vector<int> mxl;
    mxl.push_back(v[0]);
    vector<int> mxr;
    mxr.push_back(v[v.size()-1]);
    
    int water=0;
    
    for(int i=1;i<v.size();i++){
        if(v[i]>mxl[i-1]){
            mxl.push_back(v[i]);
        }
        else{
            mxl.push_back(mxl[i-1]);
        }
    }
    
    int j=0;
    for(int i=v.size()-2;i>=0;i--){
        if(v[i]>mxr[j]){
            mxr.push_back(v[i]);
        }
        else{
            mxr.push_back(mxr[j]);
        }
        j++;
    }
    reverse(mxr.begin(),mxr.end());
    
    // for(int i =0 ;i<v.size();i++){
    //     cout<<mxl[i]<<" ";
    // }
    // cout<<endl;

    // for(int i =0 ;i<v.size();i++){
    //     cout<<mxr[i]<<" ";
    // }
    // cout<<endl;

    for(int i=0;i<v.size();i++){
        water+= min(mxr[i],mxl[i])-v[i];
    }
    cout<<water<<endl;
}


int main() {
	int t,n,temp;
	vector<int> v;
	cin>>t;
	for(int i =0;i<t;i++){
	    cin>>n;
	    for(int j=0;j<n;j++){
	        cin>>temp;
	        v.push_back(temp);
	    }
        solve(v);
        v.clear();
	}
	return 0;
}
