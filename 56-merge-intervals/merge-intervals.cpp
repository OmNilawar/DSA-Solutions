class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for(int i = 1;i < n;i++)
        {
            int prevEnd = ans[ans.size() - 1][1];

            if(prevEnd >= intervals[i][0])
                ans[ans.size()-1][1] = max(intervals[i][1], ans[ans.size() - 1][1]);
            else
                ans.push_back(intervals[i]);
        } 
        
        return ans;
    }
};