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
    
     
12.3 Insertion and deletion
-- insertion 
  //一路杀到最下面，然后看放在左边还是右边 
  TREE-INSERT(T,z)
  1 y = NIL
  2 x = T.root
  3 while x ¤ NIL
  4   y = x
  5   if z.key < x.key
  6     x = x.left
  7   else x = x.right
  8 z.p = y
  9 if y == NIL
  10  T.root =z // tree T was empty
  11 elseif z.key < y.key
  12  y.left = z
  13 else y.right = z 
  
-- Deletion 
  - most tricky part is:
    - if y is z's right child, then we replace z by y, leaving y's right child alone. 
    
    - y(successor) lies within z's right subtree but is not z's right child, in this case, we first replace y by its own right child, and       then we replace z by y.

    - alg:
      TREE-DELETE(T,z)
      1 if z.left == NIL
      2   TRANSPLANT(T,z,z.right)
      3 elseif z.right == NIL
      4   TRANSPLANT(T,z,z.left)
      5 else y = TREE-MINIMUM(z.right)
      6   if y.p != z
      7     TRANSPLANT(T, y, y.right)
      8     y.right = z.right
      9     y.right.p = y
      10  TRANSPLANT(T,z,y)
      11    y.left = z.left
      12    y.left.p =  y









