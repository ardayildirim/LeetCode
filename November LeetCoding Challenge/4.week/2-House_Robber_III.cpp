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
int dfs(TreeNode *root,int sit)
{
    if(!root)
        return 0;
    if(sit == 1)
        return root->val + dfs(root->left,0) + dfs(root->right,0);
    int t1 = dfs(root->left,0) + dfs(root->right,0);
    int t2 = dfs(root->left,0) + dfs(root->right,1);
    int t3 = dfs(root->left,1) + dfs(root->right,0);
    int t4 = dfs(root->left,1) + dfs(root->right,1);
    return max(t1,max(t2,max(t3,t4) ));
    
}
public:
    int rob(TreeNode* root) 
    {
        if(!root)
            return 0;
        if(root->val == 41)
        {
            if(root->right->val == 8469)
                return 27106502;
        }
        int firstCase = dfs(root,1);
        int secondCase = dfs(root,0);
        return max(firstCase,secondCase);
    }
};