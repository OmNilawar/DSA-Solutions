class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i = 1; i< n;i++)
        {
            if(nums[i] != nums[i-1])
                ans.push_back(nums[i]);
        }
        nums = ans;
        return ans.size();
    }
};