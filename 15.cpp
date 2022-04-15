//
// Created by admin on 2022/4/15.
//

#include <bits/stdc++.h>
using namespace  std;

<<<<<<< HEAD
vector<int> findAnagrams(string s, string p) {

    vector<int> res;

    vector<int> count_p(26,0);
    for(auto c:p){
        count_p[c-'a']++;
    }

    int l=0,r=0;
    int n = s.size();
    vector<int> count_s(26,0);

    while(r<n){
        count_s[s[r]-'a']++;

        while(r-l+1>p.size()){
            count_s[s[l]-'a']--;
            l++;
        }

        if(count_s==count_p){
            res.push_back(l);
        }

        r++;

    }


    return res;
}

int main(){
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = findAnagrams(s,p);
    for(auto c:res){
        cout<<c<<" ";
    }
    cout<<endl;
=======
int getLongest(string s1){

}

int main(){
    string s1 = "";
    int res = getLongest(s1);
    cout<<"res: "<<res<<endl;
>>>>>>> 830f3e910fd537e7e47a5d0d71d58a246ff4929f
}