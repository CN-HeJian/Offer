//
// Created by admin on 2022/4/14.
//
#include <bits/stdc++.h>
using namespace std;

int getOnlyNum(vector<int> arr){
    int n = arr.size();
    vector<int> bitsCount(32,0);
    for(int i=0;i<n;i++){
        int temp = arr[i];
        for(int j=0;j<32;j++){
            if(temp&1){
                bitsCount[j]++;
            }
            temp = temp>>1;
        }
    }
    int res = 0;
    for(int i=0;i<32;i++){
        if(bitsCount[i]%3){
            res = res | (1<<i);
        }
    }
    return res;
}


int main(){
    vector<int> arr = {0,1,0,1,0,1,100};
    int res = getOnlyNum(arr);
    cout<<"res: "<<res<<endl;
}
