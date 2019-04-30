/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int l=0, r=0;
        auto lnode = root, rnode = root; 
        while(lnode){
            l++;
            lnode = lnode->left;
        }
        while(rnode){
            r++;
            rnode = rnode->right;
        }
        if(l==r) return pow(2,l) - 1;
        return 1+countNodes(root->left) + countNodes(root->right);
    }
};
