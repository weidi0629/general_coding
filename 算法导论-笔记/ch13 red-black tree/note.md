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
 
 pending 13.2
