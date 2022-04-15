//
// Created by admin on 2022/4/15.
//
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &cur,vector<int> &target){
    for(int i=0;i<128;i++){
        if(cur[i]<target[i]){
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    vector<int> target(128,0);
    for(int i=0;i<t.size();i++){
        //cout<<t[i]-' ';
        target[t[i]-' ']++;
    }
    int l= 0,r=0;
    int n = s.size();
    vector<int> cur(128,0);

    int res  =INT_MAX;
    string r_s;

    while(r<n){
        cur[s[r]-' ']++;
        while(l<=r && check(cur,target)){

            if(res>=r-l+1){
                r_s = s.substr(l,r-l+1);
                res = r-l+1;
            }

            cur[s[l]-' ']--;
            l++;
        }
        r++;
    }

    return r_s;
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";;
    string res = minWindow(s,t);
    cout<<res<<endl;
}