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
    vector<int> sum;
    
    void dfs(TreeNode* node, int lev){
        if(!node) return;
        if(lev>sum.size()) sum.resize(lev);  // 这个resize用法要记住
        sum[lev] +=node->val;
        dfs(root->left,lev+1);
        dfs(root->right,lev+1);
    }
    
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        int res;
        for(int =1; i<sum.size();i++){
            if(sum[0]<sum[i])
                res= i;
        }
        return res;
    }
};




class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int lev=1,mx = INT_MIN,res;
        q.push(root);
        while(!q.empty()){  
            int tmpmx =0;;
            for(int i =0; i<q.size();i++){
                TreeNode* node = q.front(); q.pop();
                tmpmx += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            } 
            if(tmpmx>mx){
                mx = tmpmx;
                res = lev;
            }
            lev++;        
        }
        return res;
    }
};
