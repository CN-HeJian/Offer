//
// Created by admin on 2022/4/14.
//

#include <bits/stdc++.h>
using namespace std;

string addString(string a,string b){
    int n1 =a.size()-1;
    int n2 = b.size()-1;
    string res;
    int carry = 0;

    while(n1>=0 || n2>=0 || carry){
        int temp1 = 0;
        if(n1>=0){
            temp1 = a[n1]-'0';
            n1--;
        }
        int temp2=0;
        if(n2>=0){
            temp2 = b[n2]-'0';
            n2--;
        }
        int sum = temp1+temp2+carry;
        res = to_string(sum%2)+res;
        carry = sum/2;
    }

    return res;
}

int main(){
    string a = "1010";
    string b = "1011";
    string res = addString(a,b);
    cout<<"res: "<<res<<endl;
}