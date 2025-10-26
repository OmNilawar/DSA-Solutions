class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& time, int i, int j, int t) {
        int n = grid.size(), m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return;
        if(grid[i][j]==1 && (time[i][j]==0 || time[i][j]>t))
            time[i][j] = t;
        else if(grid[i][j]==1 && time[i][j]<=t) return;

        int temp = grid[i][j];
        grid[i][j] = 0;

        dfs(grid, time, i+1, j, t+1);
        dfs(grid, time, i-1, j, t+1);
        dfs(grid, time, i, j+1, t+1);
        dfs(grid, time, i, j-1, t+1);

        grid[i][j] = temp;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m,0));

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2)
                    dfs(grid, time, i, j, 0);

        int maxi = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1) {
                    if(time[i][j]==0) return -1;
                    maxi = max(maxi, time[i][j]);
                }

        return maxi;
    }
};
