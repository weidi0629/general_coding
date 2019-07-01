/*
             1
        3         2
     4    5    6    7
   15...
  
 这题关键是求parent， 一般二叉树，parent 就是 label/2, 这个话，要把每个label翻转。注意是每一行都要翻转，而不是看行号的奇偶，因为每一行的上一行都翻转
 过了。
 注意翻转的方法，每行的max - label + min
 
 max: (1 << level) - 1
 min: (1 << (level - 1)
   
*/

vector<int> pathInZigZagTree(int label, int level = 0) {
  while (1 << level <= label) ++level;
  vector<int> res(level);
  for(; label >= 1; label /= 2, --level) {
    res[level - 1] = label;
    label = (1 << level) - 1 - label + (1 << (level - 1));
  }
  return res;
}
