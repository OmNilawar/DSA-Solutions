class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        int i = 0;
        int j = 2;

        while(j < n)
        {
            if((nums[i]+nums[j])*2 == nums[i+1])
                count++;
            
            i++;
            j++;
        }

        return count;
    }
};