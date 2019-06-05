/*
先求prefix sum, 这样行的加总就已经提前完成了。

后面的三个循环，首先显示遍历所有列的组成。
确定两列之后，用了一个求 subarray sum的办法：

|_________|______|___________|
0         i      j 

比如最后是 i 到 j是符合要求的target，那么从 0 到 j的加总，减去 target， 就是0到i，已经记录在counter里了，所以就找到一个了。这样的方法是linear的

*/
int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int m = A.size(), n = A[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                A[i][j] += A[i][j - 1];
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {  // 遍历所有的两列
                unordered_map<int, int> counter;
                counter[0] = 1;
                int cur = 0;
                for (int k = 0; k < m; k++) {
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);  // 因为是prefix sum， 所以一减就是两个的加总了
                    res += counter[cur - target];
                    counter[cur]++; 
                }
            }
        }
        return res;
    }
    
    /*
    还有一个python版本 意思是一样的
    
        m, n = len(A), len(A[0])
        for row in A:
            for i in xrange(n - 1):
                row[i + 1] += row[i]
        res = 0
        for i in xrange(n):
            for j in xrange(i, n):
                c = collections.Counter({0: 1}) #默认 0的个数是1
                cur = 0
                for k in xrange(m):
                    cur += A[k][j] - (A[k][i - 1] if i > 0 else 0)
                    res += c[cur - target]
                    c[cur] += 1
        return res
    
    */
