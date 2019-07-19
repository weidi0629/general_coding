class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        preorder(root, nullptr);
        vector<int> res, aux;
        res.push_back(target->val);
        unordered_set<int> vis;
        vis.insert(target->val); // target 是一个可以出发的点 
        for (int d = 0; d < K; d++) {
            for (auto u : res) {
                for (auto v : dict[u]) {
                    if (vis.count(v)) continue;
                    vis.insert(v);
                    aux.push_back(v);
                }
            }
            res.clear();
            swap(res, aux);  // 用swap方法来做bfs 
        }
        return res;
    }
    
    void preorder(TreeNode* p, TreeNode* parent) {
        if (p == nullptr) return;
        if (parent) {
            dict[p->val].insert(parent->val);
            dict[parent->val].insert(p->val);
        }
        if (p->left)  preorder(p->left,  p);
        if (p->right) preorder(p->right, p);
    }
    
private:
    unordered_map<int,unordered_set<int>> dict;
};
