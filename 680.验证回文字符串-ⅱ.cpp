/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int left=0,right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
                return judge(s,left+1,right) || judge(s,left,right-1); 
            }
            left++;
            right--;
        }
        return true;
    }
    bool judge(string s,int left,int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

