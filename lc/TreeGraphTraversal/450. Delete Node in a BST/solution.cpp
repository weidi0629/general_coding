/*
结合算法导论上的理论知识
*/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val == key){
            if(!root->right){
                TreeNode* left = root->left;
                delete root;
                return left;  // 因为是递归，这里算找到了 
            }else{
               TreeNode* right = root->right;
                while (right->left)
                    right = right->left;
                swap(root->val, right->val);    
            }
                
        }
        root->left = deleteNode(root->left, key); // 递归的整之后的事情
        root->right = deleteNode(root->right, key);  
        return root; 
    }    
};
