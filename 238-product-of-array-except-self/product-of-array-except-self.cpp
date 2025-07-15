class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int sum = 1;

        for(int i = 0;i < n;i++)
        {
            if(nums[i] == 0)
                zeroCount++;
            
            else
                sum *= nums[i];
        }

        if(zeroCount > 1)
            return vector<int>(n,0);
        
        if(zeroCount == 1)
        {
            vector<int> ans(n,0);

            for(int i = 0;i < n;i++)
                if(nums[i] == 0)
                {
                    ans[i] = sum;
                    break;
                }
            
            return ans;
        }

        vector<int> ans;

        for(int i = 0;i < n;i++)
        {
            ans.push_back(sum/nums[i]);
        }

        return ans;
    }
};