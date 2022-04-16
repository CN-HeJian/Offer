//
// Created by admin on 2022/4/16.
//
#include <bits/stdc++.h>
using namespace std;

bool isPanic(string s,int left,int right);

bool validPalindrome(string s) {
    int l=0,r=s.size()-1;

    while(l<r){
        if(s[l]==s[r]){
            l++;
            r--;
        }else{
            return isPanic(s,l+1,r)||isPanic(s,l,r-1);
        }
    }

    return true;
}

bool isPanic(string s,int left,int right){
    int l = left,r =right;
    while(l<r){
        if(s[l]==s[r]){
            l++;
            r--;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    string s = "aba";
    bool res = validPalindrome(s);
    cout<<"res: "<<res<<endl;
}