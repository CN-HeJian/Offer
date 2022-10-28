/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (53.42%)
 * Likes:    716
 * Dislikes: 0
 * Total Accepted:    125.1K
 * Total Submissions: 234K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 * 
 * 
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    
        vector<int> res;

        if(p.size()>s.size()){
            return res;
        }

        
        int windowSize = p.size();
        
        vector<int> target(26,0);
        vector<int> cur(26,0);

        for(int i=0;i<windowSize;i++){
            target[p[i]-'a']++;
            cur[s[i]-'a']++;
        }


        for(int i=windowSize;i<s.size();i++){
            if(target==cur){
                res.push_back(i-windowSize);
            }

            cur[s[i]-'a']++;
            cur[s[i-windowSize]-'a']--;
            
        }

        if(target==cur){
            res.push_back(s.size()-windowSize);
        }

        return res;

    }
};
// @lc code=end

