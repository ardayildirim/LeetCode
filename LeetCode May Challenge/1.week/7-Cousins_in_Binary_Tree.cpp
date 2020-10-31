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
class Solution 
{
    vector<int> dfs(TreeNode* root,int target,int parent, int depth)
    {
        if(root == NULL)
            return {};
        if(root -> val == target)
            return {parent,depth};
        vector<int> left = dfs(root->left,target,root->val,depth+1);
        vector<int> right = dfs(root->right,target,root->val,depth+1);
        return left.empty() ? right : left;
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {
        vector<int> x_vals = dfs(root,x,-1,0); 
        vector<int> y_vals = dfs(root,y,-1,0);
        if(x_vals[0] != y_vals[0] && x_vals[1] == y_vals[1]) // dfs returns {parent,depth} 
            return true;
        return false;
    }
};
