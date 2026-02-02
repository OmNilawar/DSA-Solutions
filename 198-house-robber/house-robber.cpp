class Solution {
public:
    vector<int> memo;
    int traverse(vector<int>& nums, int n)
    {
        if(n < 0)
            return 0;

        if(memo[n] != -1)
            return memo[n];
        
        return memo[n] = max(traverse(nums, n-1), nums[n] + traverse(nums, n-2));
    }
    int rob(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        return traverse(nums, nums.size()-1);
    }
};