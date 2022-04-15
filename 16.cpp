//
// Created by admin on 2022/4/15.
//

#include <bits/stdc++.h>
using namespace  std;

int getLongest(string s1){
    int l =0,r=0;
    int n = s1.size();
    int res = 0;
    vector<int> count(128,0);
    while(r<n){
        count[s1[r]-' ']++;
        while(l<=r &&count[s1[r]-' ']>1){
            count[s1[l]-' ']--;
            l++;
        }
        res = max(res,r-l+1);
        r++;
    }
    return res;
}

int main(){
    string s1 = "abcabcbb";
    int res = getLongest(s1);
    cout<<"res: "<<res<<endl;
}