https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m)
            return 0;
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);

        for(int i = 0;i < n;i++)
        {
            arr1[s1[i] - 'a']++;
            arr2[s2[i] - 'a']++;
        }
        if(arr1 == arr2)
            return 1;
        
        for(int i = 1;i <= m-n;i++)
        {
            int j = i+n-1;
            arr2[s2[i-1] - 'a']--;
            arr2[s2[j] - 'a']++;

            if(arr1 == arr2)
                return 1;
        }

        return 0;
    }
};