//
// Created by admin on 2022/4/14.
//

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0,r=0;
    int n = nums.size();
    int sum = 0;
    int res = INT_MAX;

    while(r<n){
        sum+=nums[r];
        while(sum>=target){
            res = min(res,r-l+1);
            sum-=nums[l];
            l++;
        }
        r++;
    }

    return res==INT_MAX?0:res;
}

int main(){
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    int res = minSubArrayLen(target,nums);
    cout<<res<<endl;
}


