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
    int findHeight(TreeNode* root, int height)
    {
        if(root == nullptr)
            return height;
        
        int l = findHeight(root->left,height+1);
        if(l == -1)
            return -1;
        
        int r = findHeight(root->right,height+1);
        if(r == -1)
            return -1;
        
        if(abs(l-r) > 1)
            return -1;
        
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        
        return findHeight(root,0) != -1;
    }
};