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
private:
    int sum_list(TreeNode *root)
    {
        if(!root)
            return 0;
        int l = sum_list(root->left);
        int r = sum_list(root->right);
        return l + r + root->val;
    }
public:
    // O(n^2) runtime (bad for trees though)
    int findTilt(TreeNode* root) 
    {
        if(!root)
            return 0;
        int lsum = sum_list(root->left);
        int rsum = sum_list(root->right);
        if(lsum >= rsum)
        {
            return lsum - rsum + findTilt(root->left) + findTilt(root->right);
        }
        else
        {
            return rsum - lsum + findTilt(root->left) + findTilt(root->right);
        }
        
    }
};