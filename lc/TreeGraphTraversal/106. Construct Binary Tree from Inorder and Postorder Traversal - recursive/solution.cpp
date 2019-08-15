/*
底下这个1点是最难点， 因为 postorder模式是 [left->right->root], 而在这个left part, 模式也是 leftleft, leftright, leftroot，而我们要找的
就是这个leftroot。要知道这个，就要知道right有几个。而end-i+1就是从 inorder来找right part 有几个。
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0||postorder.size()==0) return NULL;
        return helper(inorder,0,inorder.size()-1,postorder,postorder.size()-1);
    }
    TreeNode* helper(vector<int>& inorder, int start, int end, vector<int>& postorder, int len){
        if(start>end||len <0) return NULL;
        int val = postorder[len];
        TreeNode* root=new TreeNode(val);
        int i;
        for(i=start;i<end;i++){
            if(inorder[i] == val) break;
        }
        root->right = helper(inorder,i+1,end,postorder,len-1);
        root->left = helper(inorder,start,i-1,postorder,len-(end-i+1)); // 1      
        return root;
    }
};
