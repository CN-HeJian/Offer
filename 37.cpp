//
// Created by admin on 2022/4/17.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;



vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    bool isSurvive = true;

    for(int i=0;i<asteroids.size();i++,isSurvive = true){
        if(asteroids[i]>=0){
            st.push(asteroids[i]);
        }else{
            if(st.empty() || st.top()<0) {
                st.push(asteroids[i]);
            }else {
                while(!st.empty()){
                    if(st.top() > abs(asteroids[i])){
                        isSurvive = false;
                        break;
                    }else if(st.top() == abs(asteroids[i])){
                        isSurvive = false;
                        st.pop();
                        break;
                    }else if(st.top()<0){
                        break;
                    }else{
                        st.pop();
                    }
                }
                if(isSurvive==true){
                    st.push(asteroids[i]);
                }
            }
        }
    }

    vector<int> retAsteroids;

    while (!st.empty())
    {
        int i = st.top();
        st.pop();
        retAsteroids.push_back(i);
    }

    reverse(retAsteroids.begin(),retAsteroids.end());


    return retAsteroids;

}




int main(){


}