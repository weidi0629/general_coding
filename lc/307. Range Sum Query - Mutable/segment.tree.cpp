struct treenode{ // struct 的默认是 public
    treenode* left;
    treenode* right;
    int start,end,sum;
    treenode(int a, int b):start(a),end(b),sum(0),left(nullptr),right(nullptr){}
    //每个node需要定义start跟end，在init里就忘记了
}; 

class NumArray {
public:
    
    treenode* root;
    
    treenode* init(int start, int end, vector<int>& nums){
        if (start>end) return NULL;
        treenode* root = new treenode(start,end); //初始需要start end
        if (start == end){ 
            root->sum = nums[start];
            return root;
        }
        //int mid = (start + end)/2; // 这里错了，mid需要加上base，就是start!
        int mid = start + (start + end)/2; 
        root->left = init(start,mid,nums);
        root->right = init(mid+1,end,nums);
        root->sum = root->left->sum+root->right->sum; //记住那个图的最上面三个球
        return root;
    }
    
    int update(int i, int val, treenode* root){ //只要这个有份都要加,加的是个差值
        if(root==nullptr) return 0; //别忘记corner case
        int diff;
        if(root->start == i && root->end ==i){
            diff = root->sum - val;
            root->sum = val;
            return diff;
        }
        int mid = (root->start+root->end)/2; //这里的二分不需要加base！
        if(i>mid){
            diff =update(i,val,root->right);
            //root.right.sum += diff; 这里错了，这样写root的sum怎么办
        }else{
            diff =update(i,val,root->left);
           // root.left.sum += diff;
        }
        root->sum += diff;
        return diff;
    }
    
    int query(int start, int end, treenode* root){
        if(root == nullptr) return 0;
        //if(start<end) return 0; 这句不需要
        if(root->start == start && root->end == end) return root->sum;
        int mid = (root->start+root->end)/2;//这里的二分不需要加base！
        //if(start>mid) return query(mid,end,root); //这两句完全错了，不需要改变start,end的值
        //if(start<mid&&end<root.end) return query(start,mid,root);
        if(start>mid) return query(start,end,root->right);
        if(end<mid) return query(start,end,root->left);
        root->sum += query(start,mid,root->left) + query(mid+1,end,root->right);
        return root->sum;
    }
    
    NumArray(vector<int> nums) {
        int n = nums.size();
        init(0,n,nums);
    }
    
    void update(int i, int val) {
        update(i,val,root);
    }
    
    int sumRange(int i, int j) {
        return query(i,j,root);
    }
};
