算法导论： 
-- subproblems share subsubproblems
-- general 4 steps
  - 1. Characterize the structure of an optimal solution.  -- dp[i][j]代表什么 
  - 2. Recursively define the value of an optimal solution. -- 跟sub-problem的关系, 如何split 
  - 3. Compute the value of an optimal solution, typically in a bottom-up fashion.
-- optimal substructure: 
  - optimal solutions to a problem incorporate optimal solutions to related subproblems, which we may solve independently.
-- time-memory trade-off: as long as distinct problem is in ploynomial size 

-- optimal substructure -> overlapping subproblem 

-- matrix multiplication 
   for l =2 to n
    for i = i to n-l+1
      j = i+l-1
     ...
   注意这个 l 是 i->j的长度，l ==0 时，也就是没有乘法，所以都是0. 剩下的从2开始算。 

-- common patterns:
1. show the problem is about to make a choice, this choice leads more subproblem 
2. this choice lead to optimal suolution
3. 如何定义subproblem space 
4. "cut and paste" suppose subproblem is not optimal, 取好的留差的，也就是DP 公式

-- informally, 时间复杂度是 # of choice, and how many subproblem 
  - the cost itself, 比如cutting rod 里的pi， matrix multiplication里的 pi-1 * pk * pj

-- different between normal DP and NP hard
  - the subproblems are not independent. e.g longest and shortest sub path  
  
-- overlappin subproblems
  - different from divide and conqur 

-- 15.4 LCS
-- 关键的theorem 
Let X =  <x1, x2, ... xm> and Y = <y1, y2 .... ym> be sequences, and let Z = <z1, z2 .. zk>be any LCS of X and Y .
1. If xm = yn, then zk = xm = yn and Zk-1 is an LCS of Xm-1 and Yn-1.
2. If xm != yn, then zk != xm implies that Z is an LCS of Xm-1 and Y .
3. If xm != yn, then zk != yn implies that Z is an LCS of X and Yn-1.

2D -> 1D 习题15.4.4
如果 dp[i][j] 只跟 dp[i-1][j-1] dp[i][j-1] dp[i-1][j]
只要定义一个 dp[j], j 之前的数是本轮已经更新过的，j开始到最后（包括 j）是之前一轮的，现在要更新的。唯一一个就是 dp[i-1][j-1], 也就是更新完的 dp[j], 每次开始前要寄存掉，不然无处安放。



