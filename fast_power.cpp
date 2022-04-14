//
// Created by admin on 2022/4/14.
//
#include <bits/stdc++.h>
using namespace std;

double quickMul(double x,long long N){
    double ans = 1.0;
    double x_contribution = x;
    while(N>0){
        if(N%2==1){
            ans *= x_contribution;
        }
        x_contribution *= x_contribution;
        N = N>>1;
    }
    return ans;
}

double power(double x,double n){
    long long N = n;
    return N>=0? quickMul(x,N):1.0/ quickMul(x,-N);
}

int main(){
    int x = 2.0;
    int n = -10;
    double res = power(x,n);
    cout<<"res: "<<res<<endl;
}
