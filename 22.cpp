//
// Created by admin on 2022/4/16.
//

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int val_):val(val_),next(nullptr){}
};

ListNode* haveCycle(ListNode* head){
    if(head==nullptr || head->next == nullptr){
        return nullptr;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    bool res = true;

    while(true){
        if(fast->next==nullptr || fast->next->next==nullptr){
            return nullptr;
        }
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast){
            break;
        }
    }

    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
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
    //cycle yes
    node4->next = node2;

    ListNode* res = haveCycle(head);
    cout<<"res: "<<res->val<<endl;

    return 0;
}
