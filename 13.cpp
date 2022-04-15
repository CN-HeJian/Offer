//
// Created by admin on 2022/4/15.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> mat = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
vector<vector<int>> query = {{2,1,4,3},{1,1,2,2},{1,2,2,4}};
vector<vector<int>> sum;
vector<int> res;

void NumMatrix() {
    //init
    int m = mat.size();
    int n = mat[0].size();
    sum.resize(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j =1;j<=n;j++){
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + mat[i-1][j-1];
        }
    }
}

void sumRegion() {
    //query
    for(auto c:query){
        int row1 = c[0];
        int col1 = c[1];
        int row2 = c[2];
        int col2 = c[3];
        int r = sum[row2+1][col2+1]+sum[row1][col1]-sum[row1][col2+1]-sum[row2+1][col1];
        res.push_back(r);
    }
}

int main(){
    NumMatrix();
    sumRegion();
    for(auto c:res){
        cout<<c<<" "<<endl;
    }
    cout<<endl;
}
