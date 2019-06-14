-- properties of red-black tree
  - very node has extra storage: color
  - 保证每条path不会比其他的长两倍 -- balanced 
  - 几条properties 
    - Every node is either red or black.
    - The root is black.
    - Every leaf (NIL) is black.
    - If a node is red, then both its children are black.
    - For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
    
  - black-height
    - number of black nodes on any simple path 有几个黑的
  
  - Lemma
    - A red-black tree with n internal nodes has height at most 2lg(n+1)
 
-- Rotation 
  - change the pointer structure through rotation 

// 严格按照定义 
LEFT-ROTATE(T, x)
1 y = x.right // set y
2 x.right = y.left // turn y’s left subtree into x’s right subtree
3 if y.left != T.nil
4   y.left.p = x
5 y.p = x.p // link x’s parent to y
6 if x.p == T.nil
7   T.root = y
8 elseif x == x.p.left
9   x.p.left = y
10 else x.p.right = y
11 y.left = x // put x on y’s left
12 x.p = y


-- Insertion 13.3
  - 有点像正常二叉树的插入，单后面要做个fix，保证红黑树的property remains, 新插入的node设定成红色

  -- only two property might violate
    - Z is the root， 因红黑树要保证root 是黑色的
    - red node cannot has red child 





















