//
// Created by admin on 2022/4/15.
//

#include <bits/stdc++.h>
using namespace std;

int getSubArray(vector<int>&array,int target){
    int n = array.size();
    int sum = 0;
    unordered_map<int,int> mp;
    int res = 0;
    mp[0]=1;
    for(int i=0;i<n;i++){
        sum+=array[i];
        if(mp.find(sum-target)!=mp.end()){
            res+=mp[sum-target];
        }
        mp[sum]++;
    }
    return res;
}


int main(){
    vector<int> array = {1,2,3};
    int target = 3;
    int res = getSubArray(array,target);
    cout<<"res: "<<res<<endl;
}
