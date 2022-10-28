/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        vector<bool> exit(128,false);
        int t_len = t.size();
        for(auto c:t){
            exit[c] = true;
            //mp[c]=0;
            need[c]++;
        }
        int l=0,r=0,start=0,length=INT_MAX;
        
        while(r<s.size()){
            if(exit[s[r]]==true && need[s[r]]>0){  //表示这个字符串起到了作用
                t_len--;
                need[s[r]]--;
            }

            if(t_len==0){
                while(l<r&&(need[s[r]]==false ||  need[s[l]]<0 )){//如果失败
                    //need[s[l]]++;
                    l++;
                }
                if(r-l+1<length){
                    length = r-l+1;
                    start = l;
                }
                need[s[l]]++;
                l++;
                t_len++;
            }
            //r++;
        }
        return length==INT_MAX?"":s.substr(l,length);
    }
};
// @lc code=end

