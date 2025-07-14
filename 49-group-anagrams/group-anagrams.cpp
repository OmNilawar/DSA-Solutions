class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mpp;
        vector<vector<string>> ans;
        int n = strs.size();

        for(int i = 0;i < n;i++)
        {
            string temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            if(mpp.find(strs[i]) == mpp.end())
            {
                ans.push_back({temp});
                mpp[strs[i]] = ans.size() - 1;
            }

            else
            {
                ans[mpp[strs[i]]].push_back(temp);
            }
        }

        return ans;
    }
};