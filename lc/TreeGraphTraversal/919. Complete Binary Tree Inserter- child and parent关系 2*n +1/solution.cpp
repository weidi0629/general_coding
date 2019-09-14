/*
这题要点要点是child与parent关系，以及第一个数组的bfs的用法


Store tree nodes to a list self.tree in bfs order.
Node tree[i] has left child tree[2 * i + 1] and tree[2 * i + 2]

So when insert the Nth node (0-indexed), we push it into the list.
we can find its parent tree[(N - 1) / 2] directly.

C++:
*/
vector<TreeNode*> tree;
CBTInserter(TreeNode* root) {
    tree.push_back(root);
    for(int i = 0; i < tree.size();++i) { //注意这个i一开始初始以后就一直往上在走，所以从0没事没有问题，但size每一轮也在涨 
        if (tree[i]->left) tree.push_back(tree[i]->left); 
        if (tree[i]->right) tree.push_back(tree[i]->right);
    }
}

int insert(int v) {
    int N = tree.size();
    TreeNode* node = new TreeNode(v);
    tree.push_back(node);
    if (N % 2) // 原来的关系 2*n+1 ， 找parent是 (n-1)/2
        tree[(N - 1) / 2]->left = node;
    else
        tree[(N - 1) / 2]->right = node;
    return tree[(N - 1) / 2]->val;
}

TreeNode* get_root() {
    return tree[0];
}
    
/*
还有一个用queue的方法
*/
    
class CBTInserter {
public:
    TreeNode* root;
    CBTInserter(TreeNode* root) {
        this->root = root;
    }
    
    int insert(int v) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* newNode = new TreeNode(v);
        while(1){
            auto node = q.front();
            q.pop();
            if(node->left!=nullptr&&node->right!=nullptr){
                q.push(node->left);
                q.push(node->right);
            }else{
                if(node->left==nullptr){
                    node->left = newNode;
                }else{
                    node->right = newNode;
                }
                return node->val;
            }
        }
    }
    
    TreeNode* get_root() {
        return root;
    }
};    
    
    
    
