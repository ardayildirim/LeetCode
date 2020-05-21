// Both memory and time complexity is O(n) where n is the 
// number of elements in the tree. Because we visit each node
// only once and store its value at a vector
class Solution {
    vector<int> v;
    void dfs(TreeNode* node)
    {
        if(node == nullptr)
            return;
        dfs(node -> left);
        v.push_back(node -> val);
        dfs(node -> right);
    }
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        dfs(root);
        return v[k-1];
    }
};
