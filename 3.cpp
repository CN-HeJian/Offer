//
// Created by admin on 2022/4/14.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> getOneNums(int n){
    vector<int> dp(n+1,0);
    for(int i=0;i<=n;i++){
        if(i%2==1) {
            dp[i] = dp[i>>1]+1;
        }else{
            dp[i] = dp[i>>1];
        }
    }
    return dp;
}

int main(){
    int n = 15;
    vector<int> res = getOneNums(n);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
