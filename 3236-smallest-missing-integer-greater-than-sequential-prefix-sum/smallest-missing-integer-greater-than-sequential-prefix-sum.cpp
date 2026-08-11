class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0;i < n;i++)
        {
            mpp[nums[i]]++;
        }

        int prefix = nums[0];

        for(int i = 1;i < n;i++)
        {
            if(nums[i]-1 == nums[i-1])
            {
                prefix += nums[i];
            }
            else
                break;
        }

        while(mpp.find(prefix) != mpp.end())
        {
            prefix++;
        }

        return prefix;
    }
};