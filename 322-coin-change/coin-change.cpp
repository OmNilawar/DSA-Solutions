class Solution {
public:
    int traverse(vector<int>& coins, int amount, int i)
    {
        if(amount == 0)
            return 0;
        
        if(i < 0)
            return 1e9;
        
        if(amount >= coins[i])
            return min(traverse(coins, amount, i-1), 1 + traverse(coins, amount-coins[i], i));
        
        return traverse(coins, amount, i-1);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));

        for(int j = 0;j <= amount; j++)
            dp[0][j] = 1e9;

        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= amount;j++)
            {
                if(j >= coins[i-1])
                    dp[i][j] = min(dp[i-1][j], dp[i][j - coins[i-1]] + 1);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][amount] == 1e9 ? -1 : dp[n][amount];
    }
};