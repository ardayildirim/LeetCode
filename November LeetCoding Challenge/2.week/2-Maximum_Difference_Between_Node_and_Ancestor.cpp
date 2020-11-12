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
#define INIT_VAL 200000
class Solution {

private:
    
    int ans = 0;
    
    int temp_min = INIT_VAL;
    int temp_max = -1;
    
    void dfs(TreeNode *root)
    {
        if(!root)
            return;


        int lmin = find_min(root->left);
        int lmax = find_max(root->left);
        
        int rmin = find_min(root->right);
        int rmax = find_max(root->right);
        
        
        if( abs(root->val - lmin) > ans && lmin != INIT_VAL )
            ans = abs(root->val - lmin);
        
        if( abs(root->val - rmin) > ans  && rmin != INIT_VAL )
            ans = abs(root->val - rmin);
        
        if( abs(root->val - lmax) > ans && lmax != -1 ) 
            ans = abs(root->val - lmax);
        
        if( abs(root->val - rmax) > ans && rmax != -1)
            ans = abs(root->val - rmax);
        
        dfs(root->left);
        dfs(root->right);
        
        return;
    }
    
    int find_max(TreeNode *root)
    {
        temp_max = -1;
        find_max_helper(root);

        return temp_max;
    }
    void find_max_helper(TreeNode *root)
    {
        if(!root)
            return;
        if(root->val >= (temp_max))
            temp_max = (root -> val);
        find_max_helper(root->left);
        find_max_helper(root->right);
        return;
    }
    
    int find_min(TreeNode *root)
    {
        temp_min = INIT_VAL;
        find_min_helper(root);

        return temp_min;
    }
    void find_min_helper(TreeNode *root)
    {
        if(!root)
            return;
        if(root->val <= (temp_min))
            temp_min = (root -> val);
        find_min_helper(root->left);
        find_min_helper(root->right);
        return;
    }
    
public:
    int maxAncestorDiff(TreeNode *root) 
    {
        ans = 0;
        dfs(root);
        return ans;
        
    }
};