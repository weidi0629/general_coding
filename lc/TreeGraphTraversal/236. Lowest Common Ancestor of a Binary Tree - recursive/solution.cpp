/*
这题的代码看似简单，但是一道值得思考的recursive。第二次做还是没有想出来，说明还是不够扎实。
这题很容易想到如果 node的left,right如果正好是p q，那么就返回这个东西。
那考虑如果这个node不是root，而是当中的某个点，那它上面这个node（暂时称parent，node是他的left）怎么办呢，返回那个？
那parent的left是应该返回的，右边没有东西，那就返回这个left，一直到头，最后这句话也就出来了：return left!=nullptr?left:right;  
考虑如果 p->q这种情况，其实q都不用往下去找，只要p的parent右边什么都找不到，那就一直返回p就好。
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr|| root == p || root ==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left&&right) return root;
        return left!=nullptr?left:right;     
    }
};

