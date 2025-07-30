class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>> stk;
        int maxHist = 0;

        for(int i = 0;i < n;i++)
        {
            int start = i;
            while(!stk.empty() && stk.top().first > heights[i])
            {
                pair<int,int> temp = stk.top();
                maxHist = max(maxHist,(temp.first * (i - temp.second)));
                start = stk.top().second;
                stk.pop();
            }

            stk.push({heights[i],start});
        }

        while(!stk.empty())
        {
            pair<int,int> temp = stk.top();
            maxHist = max(maxHist,(temp.first * (n - temp.second)));
            stk.pop();
        }

        return maxHist;
    }
};