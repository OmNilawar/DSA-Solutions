class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        map<int,int> mpp;

        for(int i = 0;i < n;i++)
        {
            mpp[nums[i]]++;
        }


        int prev;
        int maxLen = 0;
        int len = 1;
        bool isFirst = true;

        for(auto& mp : mpp)
        {
            if(isFirst)
            {
                isFirst = false;
                prev = mp.first;
            }
            else if(mp.first == prev+1)
            {
                len++;
                prev = mp.first;
            }
            else
            {
                maxLen = max(maxLen,len);
                len = 1;
                prev = mp.first;
            }
        }

        maxLen = max(maxLen,len);

        return maxLen;
    }
};
