class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(n != m)
            return false;

        vector<int> mpp1(26,0),mpp2(26,0);

        for(int i = 0;i < n;i++)
        {
            mpp1[s[i] - 'a']++;
            mpp1[t[i] - 'a']--;
        }

        
        
        return mpp1 == mpp2;
    }
};