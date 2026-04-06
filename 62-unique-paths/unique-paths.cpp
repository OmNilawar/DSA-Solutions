class Solution {
public:
    int traverse(int i, int j)
    {
        if(i < 0 || j < 0)
            return 0;
        
        if(i == 0 && j == 0)
            return 1;
        
        return traverse(i-1, j) + traverse(i, j-1);
         
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        dp[1][1] = 1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(i == 1 && j == 1)
                    continue;
                
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[n][m];
    }
};