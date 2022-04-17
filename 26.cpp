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


ListNode* findMid(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next && fast->next->next!=nullptr){
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

void mergeList(ListNode* l1,ListNode*l2){
    ListNode* temp1;
    ListNode* temp2;
    while(l1&&l2){
        ListNode* templ1 = l1->next;
        ListNode* templ2 = l2->next;

        l1->next = l2;
        l1 = templ1;

        l2->next = l1;
        l2 = templ2;
    }
}


void reorderList(ListNode* head) {
    ListNode* mid = findMid(head);

    ListNode* l1 = head;
    ListNode* l2 = mid->next;

    mid->next = nullptr;

    ListNode* ret = reverse(l2);

    mergeList(l1,ret);
}