/*
相比于serialize general tree, 这题的难度是如何运用bst的特性： 左边都小，右边的都大

下面是第一种方法，大小queue， 左边都给小q，右边的都给大q。 另外是用stack代替recursive的练习 
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

/*
另外一种方法是设定上下界限 

      7
    /   \
   5      12
 /  \
2    6   ... 

比如 7的左边都应该比7小，7就变成了上限，而5的右边，7是上限，而5是下限， recursive是反复迭代上下限是要点 

讨论里java是常规做法，下面是cpp利用了 mem

*/


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string order;
        inorderDFS(root, order);
        return order;
    }
    
    inline void inorderDFS(TreeNode* root, string& order) {
        if (!root) return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars
        for (int i=0; i<4; i++) order.push_back(buf[i]);
        inorderDFS(root->left, order);
        inorderDFS(root->right, order);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos, INT_MIN, INT_MAX);
    }
    
    inline TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
        if (pos >= buffer.size()) return NULL; //using pos to check whether buffer ends is better than using char* directly.
        
        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue) return NULL;
        
        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        node->left = reconstruct(buffer, pos, minValue, value);
        node->right = reconstruct(buffer, pos, value, maxValue);
        return node;
    }
};



