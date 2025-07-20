class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre;
        vector<int> post;

        int preMax = -1;
        int postMax = -1;

        for(int i = 0;i < n;i++)
        {
            pre.push_back(preMax);
            preMax = max(preMax,height[i]);
        }

        for(int i = n-1;i >= 0;i--)
        {
            post.push_back(postMax);
            postMax = max(postMax,height[i]);
        }

        reverse(post.begin(),post.end());
        int totalWater = 0;

        for(int i = 0;i < n;i++)
        {
            if(pre[i] == -1 || post[i] == -1)
                continue;
            
            int minLevel = min(pre[i],post[i]);
            if(minLevel > height[i])
                totalWater += minLevel - height[i];
        }

        return totalWater;
    }
};