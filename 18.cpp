//
// Created by admin on 2022/4/16.
//

#include <bits/stdc++.h>
using namespace  std;

bool isPanic(string s){
    int l= 0;
    int r= s.size()-1;
    while(l<r){
        while(l<r && !(isalnum(s[l]))){
            l++;
        }
        while(l<r && !(isalnum(s[r]))){
            r--;
        }
        if(l<r){
            if(tolower(s[l])!= tolower(s[r])){
                return false;
            }
            else{
                l++;
                r--;
            }
        }
    }
    return true;
}


int main(){
    string s = "A man, a plan, a canal: Panama";
    int res = isPanic(s);
    cout<<"res: "<<res<<endl;
}