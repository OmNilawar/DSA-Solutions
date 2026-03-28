class Solution {
public:
    void traverse(vector<vector<char>>& board, int i, int j)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '.')
            return ;
        
        board[i][j] = '.';
        traverse(board, i, j-1);
        traverse(board, i, j+1);
        traverse(board, i-1, j);
        traverse(board, i+1, j);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;

        for(int i = 0;i < n;i++)
        {
            for(int j = 0; j < m;j++)
            {
                if(board[i][j] == 'X')
                {
                    traverse(board, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};