class Solution {
public:
    void traverse(vector<vector<int>>& grid, vector<vector<int>>& result, int i, int j, int k)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return ;
        
        if (result[i][j] != 0 && result[i][j] <= k)
            return;

        if(grid[i][j] == 1)
            if(result[i][j] == 0 || result[i][j] > k)
                result[i][j] = k;

        int temp = grid[i][j];
        grid[i][j] = 0;

        traverse(grid, result, i+1, j, k+1);
        traverse(grid, result, i-1, j, k+1);
        traverse(grid, result, i, j+1, k+1);
        traverse(grid, result, i, j-1, k+1);

        grid[i][j] = temp;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> result(n, vector<int>(m,0));

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 2)
                    traverse(grid, result, i, j, 0);
            }
        }

        int maxi = 0;

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 1 && result[i][j] == 0)
                {
                    return -1;
                }
                maxi = max(maxi, result[i][j]);
            }
        }
        
        return maxi;
    }
};