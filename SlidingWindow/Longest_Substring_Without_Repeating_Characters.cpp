https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char,int> Cmap;

        while(j < n)
        {
            if(Cmap[s[j]] == 0)
                Cmap[s[j]]++;
            
            if(Cmap[s[j]] == 1)
            {
                while(Cmap[s[j]] != 0)
                {
                    Cmap[s[i]]--;
                    i++;
                }
                Cmap[s[j]]++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};