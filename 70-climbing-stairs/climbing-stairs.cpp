class Solution {
public:
    vector<int> memo;
    int traverse(int n)
    {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(memo[n] != -1)
            return memo[n];

        return memo[n] = traverse(n-1) + traverse(n-2);
    }
    int climbStairs(int n) {
        memo.assign(n+1, -1);
        return traverse(n);
    }
};