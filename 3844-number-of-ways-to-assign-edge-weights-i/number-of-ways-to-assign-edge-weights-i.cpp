class Solution {
public:
    int traverse(vector<vector<int>>& adj, int curr, int parent)
    {
        int depth = 0;

        for(auto node: adj[curr])
        {
            if(node == parent) continue;
            depth = max(depth, traverse(adj, node, curr) + 1);
        }

        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int depth = traverse(adj, 1, 0);
        int ans = 1;

        while(--depth)
            ans = (ans * 2) % 1000000007;

        return ans;
    }
};