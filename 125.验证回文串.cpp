/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */



// @lc code=start

bool isType(char a);

bool isType(char a){
    return (a>='a'&&a<='z') || (a>='A'&&a<='Z') ||(a>='0'&&a<='9');
}
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0,right = s.size();
        while(left<right){
            while(left<right && !isType(s[left])){
                left++;
            }
            while(left<right && !isType(s[right])){
                right--;
            }
            s[left] = toupper(s[left]);
            s[right] = toupper(s[right]);


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

