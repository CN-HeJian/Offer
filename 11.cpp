//
// Created by admin on 2022/4/15.
//

#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums){
    int res = 0;
    unordered_map<int,int> mp;
    int count = 0;
    mp[count] = -1;
    int n = nums.size();

    for(int i=0;i<n;i++){
        if(nums[i]==1){
            count++;
        }else if(nums[i]==0){
            count--;
        }
        if(mp.find(count)!=mp.end()){
            res = max(res,i-mp[count]);
        }else{
            mp[count] = i;
        }
    }

    return res;
}

int main(){
    vector<int> arr = {0,1,0,1,1,1,0,0};
    int res = findMaxLength(arr);
    cout<<"res: "<<res<<endl;
}
