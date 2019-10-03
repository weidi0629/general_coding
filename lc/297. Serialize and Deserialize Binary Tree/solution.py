/*
感觉还是这个版本最好
自己做的时候没有考虑到 spliter，有的人用的是都好，但发现用这个 ostringstream 最方便

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74259/Recursive-preorder-Python-and-C%2B%2B-O(n)
*/
class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};



class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        def doit(node):
            if node:
                res.append(str(node.val))
                #res.append(doit(root.left)) #这里错了，不需要append,递归里面会append的
                #res.append(doit(root.right)) 
                doit(root.left)
                doit(root.right)
            else:
                res.append("#")
            res=[]
            doit(root)
            #return ' '.join(res.split()) 这里错了，join可以直接接list
            return ' '.join(res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.     
        :type data: str
        :rtype: TreeNode
        """
        def doit:
            val = next(sd) # 这句跟下面split很重要，要学会。iterator的概念应该跟cpp里一样
            if val=='#':
                return None
            else:
                node = new TreeNode(val)
                node.left = doit()
                node.right = doit()
                return node
        
        sd = iter(data.split()) # 这句跟上面的next很重要，要学会
        node = doit()
        return node
