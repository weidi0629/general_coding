class Solution {
public:
    struct node{
        int val;
        node* left, right;
        
        node(int v){
            val = v;
            left = right = nullptr;
        }
    }
    
    int search(node* root, int val){
        if(!root) return 0;
        if(root->val == val) return val;
        else if(root->val < val){
            return search(root->right,val);
        }else{
            return root->val + search(root->left,val); // (1)
        }
    }
    
     
    
    node insert(node* root, val){
        if(!root){
            root = new node(val);
        }
        else if(root->val == val)
            root->val++;
        else if(root->val < val){
            root->val++; //比自己的大，就帮他记录了，所以在search (1) 时，如果发现node->val > val,直接到node左边找就行了，因为比自己大的已经记录了
            root->right = insert(root->right,val);
        }else{                 
            root->left = insert(root->left,val);
        }
        return root;           
    }
    
    
    int reversePairs(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        node* root = nullptr;
        int res = 0;
        
        for(auto n:nums){
            res += search(root, 2L*n+1);
            root = insert(root, val);
        }
        return res;
    }
};
