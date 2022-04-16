//
// Created by admin on 2022/4/16.
//
#include <iostream>
using namespace  std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int val_):val(val_),next(nullptr){}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* slow = dummy;
    ListNode* fast = head;
    for(int i=0;i<n;i++){
        fast = fast->next;
    }

    while(fast!=nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
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
    node4->next = nullptr;

    ListNode* res = removeNthFromEnd(head,3);

    while(res){
        cout<<res->val<<" ";
        res = res->next;
    }

    return 0;
}
