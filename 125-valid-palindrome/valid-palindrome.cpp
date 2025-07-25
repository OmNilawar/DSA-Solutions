class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;

        while(l <= r)
        {
            while(!isalnum(s[l]) && l < r)
                l++;
            
            while(!isalnum(s[r]) && r > l)
                r--;
            
            if(tolower(s[l]) != tolower(s[r]))
                return false;
            
            l++;
            r--;
        }

        return true;
    }
};