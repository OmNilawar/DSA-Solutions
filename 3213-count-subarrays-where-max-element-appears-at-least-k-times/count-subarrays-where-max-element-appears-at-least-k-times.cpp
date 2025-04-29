class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> Fullmpp;
        int maxi = -1;

        for(int i : nums)
        {
            Fullmpp[i]++;
            maxi = max(maxi,i);
        }

        if(Fullmpp[maxi] < k)
            return 0;
        
        int l = 0;
        int r = 0;
        long long count = 0;
        unordered_map<int,int> mpp;

        while(r < n)
        {
            mpp[nums[r]]++;

            while(mpp[maxi] >= k)
            {
                count += (n - r);
                mpp[nums[l]]--;
                l++;
            }

            r++;
        }    

        return count;
    }
};