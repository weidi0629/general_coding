/*
有点像 cutting rod, 取后面k个里面最大的值。因为题设是要返回和，所以公式里面是加，但想法还是一样的。

dp[i] 表示到i位置所能求的最大的值 （也是题设的要求）

那比如说，最大值所能达到的状态是  [ .... j iiiii] (iiii表示后面几个数都是一样)， 而dp的subproblem就保证了 dp[j]是最优的。寻找的范围就是K

*/

int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            int curMax = 0;
            for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
                curMax = max(curMax, A[i - k + 1]);
                dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + curMax * k);
            }
        }
        return dp[N - 1];
    }
