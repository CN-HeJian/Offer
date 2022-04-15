//
// Created by admin on 2022/4/15.
//

#include <bits/stdc++.h>
using namespace  std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int l = 0,r=0;
    int multi_sum = 1;
    int n = nums.size();
    int res = 0;
    while(r<n){
        multi_sum = multi_sum*nums[r];
        while(l<=r && multi_sum>=k){
            multi_sum = multi_sum/nums[l];
            l++;
        }
        res += r-l+1;
        r++;
    }
    return res;
}

int main(){
    vector<int> array = {10,5,2,6};
    int k = 100;
    int res = numSubarrayProductLessThanK(array,k);
    cout<<res<<endl;
}
