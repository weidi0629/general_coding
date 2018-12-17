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
