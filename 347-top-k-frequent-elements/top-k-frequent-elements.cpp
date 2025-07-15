class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int i = 0;i < n;i++)
        {
            mpp[nums[i]]++;
        }
        vector<pair<int,int>> temp;

        for(auto& i : mpp)
        {
            temp.push_back({i.second,i.first});
        }

        sort(temp.begin(),temp.end());

        vector<int> ans;
        int i = temp.size() - 1;
        while(k-- && i >= 0)
        {
            ans.push_back(temp[i].second);
            i--;
        }

        return ans;
    }
};