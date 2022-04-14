//
// Created by admin on 2022/4/14.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0,r =numbers.size()-1;
    vector<int> res;

    while(l<r){
        if(numbers[l]+numbers[r]<target){
            l++;
        }
        else if(numbers[l]+numbers[r]>target){
            r--;
        }else{
            res.push_back(l);
            res.push_back(r);
            break;
        }
    }

    return res;
}

int main(){
    vector<int> arr = {1,2,4,6,10};
    int target = 8;
    vector<int> res = twoSum(arr,target);
    for(auto c:res){
        cout<<c<<" ";
    }
    cout<<endl;
}