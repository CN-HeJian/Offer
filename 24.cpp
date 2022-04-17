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


ListNode* reverseList(ListNode* head) {
    ListNode* dummy = nullptr;
    ListNode* pre = dummy;
    ListNode* cur = head;

    while(cur){
        ListNode* nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }

    return pre;
}

int main(){
    ListNode* head = new ListNode(-1);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    //cycle no
    node4->next = nullptr;

    ListNode* ret = reverseList(head);

    while(ret){
        cout<<ret->val<<" ";
        ret = ret->next;
    }

    return 0;
}