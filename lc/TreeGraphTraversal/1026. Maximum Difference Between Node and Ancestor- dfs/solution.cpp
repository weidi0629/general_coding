class Solution {
public:
    int maxdiff = 0;
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
        
    }
    
    int helper(TreeNode* root, int mn, int mx){
        if(!root) return (mx-mn);
        mx = max(mx,root->val);
        mn = min(mx,root->val);
        return max(helper(root->left, mn, mx),helper(root->right,mn,mx));
    }
    
};
