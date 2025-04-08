class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int temp = -1;
        for(int i = n-1;i >= 0;i--)
        {
            mpp[nums[i]]++;

            if(mpp[nums[i]] > 1)
            {
                temp = i;
                break;
            }
        }

        if(temp == -1)
            return 0;
        
        int i = -1;
        int count = 0;

        while(i < temp)
        {
            i += 3;
            count++;
        }

        return count;
    }
};