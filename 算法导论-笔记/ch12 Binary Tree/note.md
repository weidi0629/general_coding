12.1 what is BST
-- inorder traversal would output a sorted sequence
-- inorder take (n) time, recursive call, 一个call left, 一个call right

12.2 Querying a binary search tree
-- search 
  - 比 key 小，转做，比key 大，转右 
-- maximum and minumum
  - 就是走到最左或者最右 
-- Successor and predecessor
  - successor is the smallest key greater than x.key
  - 算法
    Tree-Successor(x):
    if x.right != null // 右边不是空的，就是右边树的最小值
        return Tree-Minimum(x.right)
    y = x.p
    while y!=null and x==y.right  //右边是空，左边就是lowest ancestor of x, 这个x的left child 也是之前的ancestor，这个条件就是用 x == y.right来判断
        x = y
        y = y.p
    return y
    
     



