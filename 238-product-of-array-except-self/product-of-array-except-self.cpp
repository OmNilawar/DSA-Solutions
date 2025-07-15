class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre;
        vector<int> post;

        pre.push_back(1);
        post.push_back(1);

        for(int i = 0;i < n;i++)
        {
            pre.push_back(pre[pre.size()-1] * nums[i]);
        }

        for(int i = n-1;i >= 0;i--)
        {
            post.push_back(post[post.size()-1] * nums[i]);
        }
        reverse(post.begin(),post.end());

        vector<int> ans;

        for(int i = 0;i < n;i++)
        {
            ans.push_back(pre[i] * post[i+1]);
        }

        return ans;
    }
};