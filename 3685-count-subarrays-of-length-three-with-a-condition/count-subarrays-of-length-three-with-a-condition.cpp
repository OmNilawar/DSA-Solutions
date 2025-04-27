class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        int i = 0;

        while(i < n-2)
        {
            if((nums[i]+nums[i+2])*2 == nums[i+1])
                count++;
            
            i++;
        }

        return count;
    }
};