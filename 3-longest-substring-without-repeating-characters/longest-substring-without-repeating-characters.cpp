class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int r = 0;
        int maxLen = 0;
        unordered_map<char,int> mpp;

        while(r < n)
        {
            mpp[s[r]]++;

            while(mpp[s[r]] > 1)
            {
                mpp[s[i]]--;
                i++;
            }
            int ans = r-i+1;
            maxLen = max(maxLen,ans);
            r++;
        }

        return maxLen;
    }
};