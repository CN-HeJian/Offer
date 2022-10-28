/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()>s2.size())
            return false;

        int windowSize = s1.size();

        vector<int> target(26,0);
        vector<int> cur(26,0);

        for(int i=0;i<windowSize;i++){
            target[s1[i]-'a']++;
            cur[s2[i]-'a']++;
        }

        for(int i=windowSize;i<s2.size();i++){
            if(target==cur){
                return true;
            }
            
            cur[s2[i]-'a']++;
            cur[s2[i-windowSize]-'a']--;

        }

        return target==cur;

    }
};
// @lc code=end

//暴力解法
