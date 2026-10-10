class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<int, int> mpp;
        long long int preSum = 0;
        long long int maxAns = 0;

        while(r < n)
        {
            mpp[nums[r]]++;
            preSum += nums[r];

            while(l <= r && (mpp[nums[r]] > 1 || r-l+1 > k))
            {
                mpp[nums[l]]--;
                preSum -= nums[l];
                l++;
            }
            if(r-l+1 == k)
                maxAns = max(maxAns, preSum);

            r++;
        }

        return maxAns;
    }
};