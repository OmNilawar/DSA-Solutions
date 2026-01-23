/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int traverse(TreeNode* root, int &ans)
    {
        if(!root)
            return 0;
        
        int left = max(0, traverse(root->left, ans));
        int right = max(0, traverse(root->right, ans));
        int sum = left + right + root->val;
        ans = max(ans, sum);

        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int temp = traverse(root, ans);

        return ans;
    }
};