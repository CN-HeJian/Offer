//
// Created by admin on 2022/4/14.
//
#include <bits/stdc++.h>
using namespace  std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());

    int l = 0,r = nums.size()-1;
    vector<vector<int>> res;
    int n =nums.size();

    for(int i=0;i<n-2;i++){
        if(nums[i]>0){
            break;
        }
        if(i>0&&nums[i]==nums[i-1]){
            continue;
        }
        int l = i+1,r = n-1;
        //cout<<i<<" "<<l<<" "<<r<<endl;
        while(l<r){
            int sum = nums[i]+nums[l]+nums[r];
            if(sum<0){
                l++;
            }else if(sum>0){
                r--;
            }else if(sum==0){
                res.push_back({nums[i],nums[l],nums[r]});
                l++;
                r--;
                while(l<n&&nums[l]==nums[l-1]){
                    l++;
                }
                while(r>=0&&nums[r]==nums[r+1]){
                    r--;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(arr);
    for(auto c:res){
        for(auto d:c){
            cout<<d<<" ";
        }
        cout<<endl;
    }
}