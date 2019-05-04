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


pending step 1 page 373
