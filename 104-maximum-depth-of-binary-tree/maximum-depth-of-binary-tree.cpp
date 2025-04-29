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
    int findMaxHeight(TreeNode* root, int height)
    {
        if(root == nullptr)
            return height;
        
        return max(findMaxHeight(root->left,height+1), findMaxHeight(root->right,height+1));
    }
    int maxDepth(TreeNode* root) {
        return findMaxHeight(root, 0);
    }
};