//
// Created by admin on 2022/4/14.
//


//  [-2^31 ,2^31-1]


#include <bits/stdc++.h>
using namespace std;

//判断z是不是大了，大了ret:true 小了ret:false
bool quickAdd(int y,int z,int x){
    int res = 0,add = y;
    while(z){
        if(z&1){
            if(res<x-add){
                return false;
            }
            res+=add;
        }
        if(z!=1){
            if(add<x-add){
                return false;
            }
            add += add;
        }
        z = z>>1;
    }
    return true;
}

int getAns(int a,int b){
    //被除数最小值
    if(a==INT_MIN){
        if(b==1){
            return INT_MIN;
        }
        if(b==-1){
            return INT_MAX;
        }
    }

    //除数最小值
    if(b == INT_MIN){
        return a == INT_MIN?1:0;
    }

    //考虑除数为0的情况
    if(a==0){
        return 0;
    }

    //全部都变成负数
    bool pos_flag = false;
    if(a>0){
        a = -a;
        pos_flag = !pos_flag;
    }
    if(b>0){
        b = -b;
        pos_flag = !pos_flag;
    }

    int left = 1, right = INT_MAX, ans = 0;
    while (left <= right) {
        // 注意溢出，并且不能使用除法
        int mid = left + ((right - left) >> 1);
        bool check = quickAdd(b, mid, a);
        //如果 false 就表示多了！
        if (check) {
            ans = mid;
            // 注意溢出
            if (mid == INT_MAX) {
                break;

            }
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }


    return pos_flag==true?-ans:ans;
}

int main(){
    int a = 15;
    int b = 2;
    int res = getAns(a,b);
    cout<<"res: "<<res<<endl;
}
