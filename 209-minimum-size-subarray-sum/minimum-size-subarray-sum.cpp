class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int temp = 0;
        int ans = INT_MAX;

        while(r < n)
        {
            temp += nums[r];

            while(l <= r && temp-nums[l] >= target)
            {
                temp -= nums[l];
                l++;
            }

            if(temp >= target)
                ans = min(ans, r-l+1);

            r++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};