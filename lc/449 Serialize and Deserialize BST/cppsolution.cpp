
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        const string sep = ",";
        string s;
        stack<int> st;
        st.push(root->val);
        while(!st.empty()){  //stack 只是用来做preorder的工具
            root = st.top();st.pop();
            s+=root->val; s+=sep;
            if(root->right) st.push(root->right->val);  //这里先搞又再搞左很要紧，解码时要用到：解码时先把小的都搞出来，剩下就都是大的了
            if(root->left) st.push(root->left->val);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<int> q;
        for(int i=0;i<data.size();i++){
            if(data[i]!=",")
                q.push(data[i]);
        }
        return get(q);
    }
    
private:    
    TreeNode* get(queue<int> q){
        TreeNode* root = q.top(); q.pop();
        queue<int> minq;
        while(!q.empty()){
            if(q.top()<root->val){  //因为之前是stack，所以一开始的一半都是小的
                minq.push(q.top()); //分两个queue是BST的特性，是关键  
                q.pop();
            }    
        }
        root->left = get(minq);
        root->right = get(q);
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
