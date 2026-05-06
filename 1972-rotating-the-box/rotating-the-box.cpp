class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        for(int i = 0;i < n;i++)
        {
            int base = m;
            for(int j = m-1;j >= 0;j--)
            {
                if(boxGrid[i][j] == '#')
                {
                    boxGrid[i][base-1] = '#';
                    base--;
                    if(j != base)
                        boxGrid[i][j] = '.';
                }
                else if(boxGrid[i][j] == '*')
                    base = j;
            }
        }

        vector<vector<char>> result(m, vector<char>(n));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                result[j][n - 1 - i] = boxGrid[i][j];
            }
        }

        return result;

    }
};