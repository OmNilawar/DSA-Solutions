//link for the problem :- https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        vector<int> ans;
        for(int i = 0;i < n;i++)
        {
            mpp[nums[i]]++;

            if(mpp[nums[i]] > 1)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};