/*
这题的关键还是如何把问题转换为LCS。有了lcs，再处理剩下的，比较straightforward
*/


string shortestCommonSupersequence(string& A, string& B) {
        int i = 0, j = 0;
        string res = "";
        for (char c : lcs(A, B)) { // 已经有LCS了，处理剩下的
            while (A[i] != c)
                res += A[i++];
            while (B[j] != c)
                res += B[j++];
            res += c, i++, j++;
        }
        return res + A.substr(i) + B.substr(j);
    }
    // 之前的LCS是求长度，这里是直接求结果，方法是一样的
    string lcs(string& A, string& B) {
        int n = A.size(), m = B.size();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (A[i] == B[j])
                    dp[i + 1][j + 1] = dp[i][j] + A[i]; // dp[i+1][j], dp[i][j+1]不可能有dp[i][j]+1大. 因为dp[i+1][j], dp[i][j+1]最后一
            // 个不一样的话，无论LCS 是什么，肯定再加上1更大。如果一样的话，还是加上1更大。
            //
                else
                    dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?  dp[i + 1][j] : dp[i][j + 1];
        return dp[n][m];
    }
