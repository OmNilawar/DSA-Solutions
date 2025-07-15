class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> temp(n+1);

        unordered_map<int,int> mpp;

        for(int i = 0;i < n;i++)
        {
            mpp[nums[i]]++;
        }

        for(auto& i : mpp)
        {
            temp[i.second].push_back(i.first);
        }

        vector<int> ans;
        int i = n;
        for(int i = n;i >= 0;i--)
        {
            for(int j = 0;j < temp[i].size();j++)
            {
                ans.push_back(temp[i][j]);
                k--;

                if(k <= 0)
                    break;
            }

            if(k <= 0)
                break;
        }

        return ans;
    }
};