class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        unordered_map<int,int> mpp;
        int ans = 0;

        while(r < n)
        {
            mpp[nums[r]]++;

            while(mpp[0] > k)
            {
                mpp[nums[l]]--;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};