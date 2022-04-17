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

ListNode*  findMid(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast->next!=nullptr && fast->next->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode* reverse(ListNode* head){
    ListNode* dummy = nullptr;
    ListNode* cur = head;
    ListNode* pre = dummy;
    while(cur){
        ListNode* nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {
    ListNode* mid = findMid(head);
    ListNode* ret = reverse(mid->next);

    ListNode* p = ret;
    ListNode* p2 = head;
    bool res = true;
    while(p){
        if(p->val!=p2->val){
            res =false;
            break;
        }
        p = p->next;
        p2 = p2->next;
    }

    mid->next = reverse(ret);

    return res;
}
