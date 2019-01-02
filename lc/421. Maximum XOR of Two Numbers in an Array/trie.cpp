class Solution {
public:
    class TreeNode {
    public:
        TreeNode* next[2]; // 首先，每个点只有两个child,所以只能二叉
        TreeNode () {next[0] = NULL; next[1] = NULL;};
    };
    TreeNode* buildTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(), *cur;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i]; //只有一棵树，每个number都是从一个root开始的
            cur = root;
            for (int j = 31; j >= 0; j--) { //而且每个number都是从最高位开始，因为跟高位决定哪个最大。
                int index = ((num >> j) & 1);
                if (cur->next[index] ==  NULL)
                    cur->next[index] = new TreeNode();
                cur = cur->next[index];
            }
        }
        return root;
    }
    
        int helper(TreeNode* cur, int num) { //每个数都要过来找跟他组成的pair的结果最大的是哪个
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = (num >> i) & 1;// 从最高位开始，保留下这一位，要么是0，要么是1
            if (cur->next[index ^ 1]) { //看看这位有没有另一个数亦或的叉有方向。注意，第一次找到，就跟着它走了，因为最高位就决定了是
                //哪个数（或者哪几个数,慢慢会淘汰下剩一个数）。而且每个路径都是一个数
                res += 1 << i; // 有就更新结果
                cur = cur->next[index ^ 1]; //沿着找到的这个数往下继续找（淘汰）
            } else {
                cur = cur->next[index]; // 没找到继续往下
            }
        }
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        TreeNode* root = buildTree(nums);
        
        for (auto i : nums) {
            res = max(res, helper(root, i));
        }
        
        return res;
    }
};
