class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        if(n == 0 && m == 0)
        {
            return {};
        }

        int i = 0;
        int j = 0;
        bool isStraight = true;
        vector<int> ans;

        while(i < n && j < m)
        {
            ans.push_back(mat[i][j]);

            if(isStraight)
            {
                if(j == m-1)
                {
                    i++;
                    isStraight = false;
                }
                else if(i == 0) 
                {
                    j++;
                    isStraight = false;
                }
                else
                {
                    i--;
                    j++;
                }
            }
            else
            {
                if(i == n-1)
                {
                    j++;
                    isStraight = true;
                }

                else if(j == 0)
                {
                    i++;
                    isStraight = true;
                }

                else
                {
                    i++;
                    j--;
                }
            }
        }

        return ans;
        
    }
};