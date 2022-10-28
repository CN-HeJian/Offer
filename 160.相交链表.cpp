/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr){
            return nullptr;
        }
        ListNode *p_a = headA,*p_b = headB;
        while(p_a!=p_b){
            p_a = p_a==nullptr?headB:p_a->next;
            p_b = p_b==nullptr?headA:p_b->next;
        }
        return p_a;
    }
};
// @lc code=end

