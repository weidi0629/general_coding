/*
从后往前要简单的多，因为新的尽量已经有它‘之后（之前）’的信息了。

如果进了的数据比要比较的node小，给这个node技术。因为如果后来再来一个这个node大的，那现在这个跟node都要要算给这个大的 
        ...
     10
    /
   5
比如现在是 10 跟 5， 10就该把5算上，因为5比他小。到下一轮，如果来一个20，注意5，跟10都是20之前（）的数，因为是倒过来的。那就应该去10的右边，
因为在5过来时，5这个书已经给10算上了，所以20也知道 

    ...
     10
    /  \
   5    20(20要把10,5这两个数都算上)

*/

class Solution {
public:
    struct treeNode{
        treeNode* left, *right;
        int sum, dup,val;
        treeNode(int v, int s){
            val =v; sum =s; dup=0;  left = right = nullptr;
        }
    };
    
    treeNode* root;
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i = n-1; i>=0; i--){
            root = update(nums[i],i,res,root,0);
        }
        return res;
    }
    
    treeNode* update(int val, int i, vector<int>& res, treeNode* root,int total){
        if(root == nullptr){
            root = new treeNode(val,0);
            res[i] = total;
        }
        if(val == root->val){
            root->dup++;
            res[i] = total+root->sum;
        }else if(val < root->val){ // samller, 去左边
            root->sum++;
            root->left = update(val,i,res,root->left,total);
        }else{
            root->right = update(val,i,res,root->right,root->sum+root->dup+total);
        }
        return root;
    }
    
};
