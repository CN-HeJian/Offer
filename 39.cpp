//
// Created by admin on 2022/4/17.
//
#include <bits/stdc++.h>
using namespace  std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    //找到左边第一个小于他的索引
    stack<int> st;
    vector<int> left(n,0);
    for(int i=0;i<heights.size();i++){
        while(!st.empty() && heights[st.top()]<heights[i]){
            st.pop();
        }
        if(!st.empty())
            left[i] = st.top();
        st.push(i);
    }

    //找到右边第一个小于他的
    stack<int> st2;
    vector<int> right;
    for(int i=n-1;i>=0;i--){
        while(!st2.empty()&&heights[st2.top()]<heights[i]){
            st2.pop();
        }
        if(st2.empty())
            right[i] = st2.top();
        st2.push(i);
    }

    int res = INT_MIN;
    for(int i=0;i<n;i++){
        int weight = right[i]-left[i];
        int area = weight*heights[i];
        res = max(res,area);
    }

    return res;
}
