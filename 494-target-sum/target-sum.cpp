class Solution {
public:
    int traverse(vector<int>& nums, int target, int n)
    {
        if(n < 0)
        {
            if(target == 0)
                return 1;
            else
                return 0;
        }

        return traverse(nums, target+nums[n], n-1) + traverse(nums, target-nums[n], n-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return traverse(nums, target, nums.size()-1);
    }
};