/*
这题的关键是建立每两个点的关系。以及swap(aux, res)的用法 
*/

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        preorder(root, nullptr);
        vector<int> res, aux;
        res.push_back(target->val);
        unordered_set<int> vis;
        vis.insert(target->val);
        for (int d = 0; d < K; d++) {
            for (auto u : res) {
                for (auto v : dict[u]) {
                    if (vis.count(v)) continue;
                    vis.insert(v);
                    aux.push_back(v);
                }
            }
            res.clear();
            swap(res, aux);
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
