class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int first = nums[0];
        int last = nums[n-1];

        int half = n/2;
        
        if(nums[half] == nums[half-1])
            return nums[half];

        if(nums[half-1] == first)
            return first;
        
        return last;
    }
};