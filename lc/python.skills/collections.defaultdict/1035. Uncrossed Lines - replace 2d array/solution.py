dp, m, n = collections.defaultdict(int), len(A), len(B)
        for i in xrange(m):
            for j in xrange(n):
                dp[i, j] = max(dp[i - 1, j - 1] + (A[i] == B[j]), dp[i - 1, j], dp[i, j - 1])
        return dp[m - 1, n - 1]
