//
// Created by admin on 2022/4/16.
//

#include <bits/stdc++.h>
using namespace std;

//回文字符串的个数
int getPanicCount(string s){
    int n = s.size();
    int count = 0;
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            //cout<<i<<" "<<j<<endl;
            if(i==j){
                dp[i][j] = true;
            }else if(i+1==j) {
                dp[i][j] = s[i]==s[j];
            }else{
                if(s[i]==s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            if(dp[i][j]){
                count++;
            }
        }
    }
    return count;
}


int main(){
    string s = "abc";
    int res = getPanicCount(s);
    cout<<"res: "<<res<<endl;
}