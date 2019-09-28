/*Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/


/*
这题几点要注意： 
以recursive的想法来看，postorder的最后一个都是root。 通过这个root，在inorder的数组里找到这个值，那么这个值得左边就都是这个root的左子树，
右边都是右子树。
recursive返回的条件就是只剩一个了。

helper function参数的意思
int idx 左子树的root
int start ： recursive inorder的开始的点 
int end : recursive inorder的结束的点

这题最关键的是求左子树时的，在postorder里的idx (也就是左子树的root)的位置
因为不断的在recursive，inorider 已经不是从0开始了, 而是start

|__________|______________|_____|
start      i             idx    end

end - i 是 i 到 end的绝对距离（右子树有几个），吧这段绝对距离往左平移，在idx处结束，也就是找到了postinorder右边右子树有几个点 


*/


public TreeNode buildTree(int[] in, int[] post) {
    if (in == null || in.length == 0 || post == null || post.length == 0) { return null; }
    return helper(post, post.length - 1, in, 0, in.length - 1);
  }
  private TreeNode helper(int[] post, int idx, int[] in, int start, int end) {
    if (start > end || idx < 0) { return null; }
    TreeNode root = new TreeNode(post[idx]);
    int i;
    for (i = start; i <= end; i++) {
      if (in[i] == root.val) {
        break;
      }
    }
    root.right = helper(post, idx - 1, in, i + 1, end);
    root.left = helper(post, idx - (end - i  + 1), in, start, i - 1); // 注意i不是一个计数，而是从start开始
    return root;    
  }
