typedef TreeNode *tp;
#define l(x) (x->left)
#define r(x) (x->right)
#define v(x) (x->val)


class Solution {
    tp dfs(tp root, int val)// idk if dfs is the correct naming i just name dfs in every tree problem
    {
        if(!root)
            return new TreeNode(val);
        
        if(val < v(root))
            l(root) = dfs(l(root),val);
        
        if(val > v(root))
            r(root) = dfs(r(root),val);
            
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        tp root;
        root = nullptr;
        for(int i : preorder)
            root = dfs(root,i);
        return root;
    }
};
