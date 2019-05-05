class Solution {
int pre = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root->right) bstToGst(root->right);
        pre = root->val = pre+root->val;
        if(root->left) bstToGst(root->left);
        return root;
    }  
};
