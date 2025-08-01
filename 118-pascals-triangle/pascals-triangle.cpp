class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1;i <= numRows;i++)
        {
            vector<int> temp(i,1);
            ans.push_back(temp);
        }

        if(numRows < 3)
            return ans;
        
        for(int i = 2;i < numRows;i++)
        {
            int n = ans[i].size();

            for(int j = 1;j < n-1;j++)
            {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }

        return ans;
    }
};