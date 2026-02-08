class Solution {
public:
    vector<vector<int>> memo;
    int traverse(string& text1, string& text2, int i, int j)
    {
        if(i < 0 || j < 0)
            return 0;
        if(memo[i][j] != -1)
            return memo[i][j];

        if(text1[i] == text2[j])
            return memo[i][j] = traverse(text1, text2, i-1, j-1) + 1;
        
        return memo[i][j] = max(traverse(text1, text2, i-1, j), traverse(text1, text2, i, j-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        memo.resize(n, vector<int>(m, -1));
        return traverse(text1, text2, n-1, m-1);
    }
};