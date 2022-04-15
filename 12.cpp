//
// Created by admin on 2022/4/15.
//

#include <bits/stdc++.h>
using namespace std;

int getAvgIndex(vector<int>& arr){
    int n = arr.size();
    vector<int> preSum(n+1,0);
    int res = -1;
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum += arr[i-1];
        preSum[i] = sum;
    }
    for(int i=0;i<n;i++){
        int half = (sum-arr[i])/2;
        int remain = (sum-arr[i])%2;
        if(remain==0 && preSum[i]==half){
            res = i;
            break;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {1,7,3,6,5,6};
    int res = getAvgIndex(arr);
    cout<<"res: "<<res<<endl;
}
