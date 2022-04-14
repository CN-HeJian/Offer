//
// Created by admin on 2022/4/14.
//

#include <bits/stdc++.h>
using namespace  std;

int maxProduct(vector<string>& words) {
    //
    int n = words.size();
    vector<int> refers(n,0);
    //怎么判断字符是否相互包含
    for(int i=0;i<n;i++){
        string temp = words[i];
        for(int j=0;j<temp.size();j++){

            refers[i] = refers[i] | (1<<(temp[j]-'a'));
        }
    }

    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((refers[i]&refers[j])==0){
                int new_res =  words[i].size()*words[j].size();
                res = max(res,new_res);
            }
        }
    }
    return res;
}

int main(){
    vector<string> words = {"a","ab","abc","d","cd","bcd","abcd"};
    int res = maxProduct(words);
    cout<<"res: "<<res<<endl;
}
