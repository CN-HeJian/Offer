/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(1280,0);  

        int res;
        int left=0,right=0;

        for(int right=0;right<s.size();right++){
            count[s[right]-' ']++;
            while(count[s[right]-' ']>1){
                //开始更新长度
                count[s[left]-' ']--;
                left++;
            }
            cout<<left<<" "<<right<<endl;
            res = max(res,right-left+1);
        }

        return res;
    }
};
// @lc code=end

