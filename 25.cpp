//
// Created by admin on 2022/4/16.
//
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val_):val(val_),next(nullptr){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    vector<int> vec1;
    vector<int> vec2;

    while(l1){
        vec1.push_back(l1->val);
        l1 = l1->next;
    }

    while(l2){
        vec2.push_back(l2->val);
        l2 = l2->next;
    }

    int p1 = vec1.size()-1;
    int p2 = vec2.size()-1;
    int carry=0;

    ListNode* dummy = nullptr;
    ListNode* r = nullptr;

    while(p1>=0 || p2>=0 ||carry){
        int temp1=0;
        if(p1>=0){
            temp1 = vec1[p1];
            p1--;
        }

        int temp2=0;
        if(p2>=0){
            temp2 = vec2[p2];
            p2--;
        }

        int sum = temp1+temp2+carry;
        int val =  sum%10;
        carry = sum/10;

        ListNode* cur = new ListNode(val);
        cur->next =  dummy;
        dummy = cur;
        r = cur;
    }

    return r;
}
