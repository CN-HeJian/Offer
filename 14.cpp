//
// Created by admin on 2022/4/15.
//

#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1,string s2){
    vector<int> vec1(26,0);
    vector<int> vec2(26,0);

    for(auto c:s1){
        vec1[c-'a']++;
    }

    int l=0,r=0;
    int n = s2.size();

    while(r<n){
        vec2[s2[r]-'a']++;
        if(r-l+1 > s1.size()){
            vec2[s2[l]-'a']--;
            l++;
        }
        if(vec1==vec2){
            return true;
        }
        r++;
    }

    return false;
}


int main(){
    string s1  = "ba";
    string s2 = "eidbaooo";
    bool res = checkInclusion(s1,s2);
    cout<<"res: "<<res<<endl;
}