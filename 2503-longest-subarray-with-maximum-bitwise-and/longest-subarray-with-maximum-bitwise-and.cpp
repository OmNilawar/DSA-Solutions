class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for(int i = 0;i < n;i++)
        {
            maxi = max(maxi,nums[i]);
        }

        int len = 0;
        int maxLen = 0;

        for(int i = 0;i < n;i++)
        {
            if(nums[i] == maxi)
                len++;
            else
                len = 0;
            
            maxLen = max(maxLen,len);
        }


        maxLen = max(maxLen,len);

        return maxLen;
    }
};