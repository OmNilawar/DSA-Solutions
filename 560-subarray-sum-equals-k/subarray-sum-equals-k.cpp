class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int preSum = 0;
        unordered_map<int, int> mpp;
        int count = 0;
        mpp[0] = 1;
        
        for(int i = 0;i < n;i++)
        {
            preSum += nums[i];

            int rem = preSum - k;

            if(mpp.find(rem) != mpp.end())
                count += mpp[rem];
            
            mpp[preSum]++;
        }

        return count;
    }
};