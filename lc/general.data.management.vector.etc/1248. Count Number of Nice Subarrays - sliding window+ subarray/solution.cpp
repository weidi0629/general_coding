/*
这题不要给subarray搞乱了，这里subarray统计的方法是倒过来的。 
比如
lets say current sub-array=[1,2,3]
when a element is added lets say 4
added sub-arrays are:
3,4
2,3,4
1,2,3,4

只要没有到规定的k值，每一步都要计算subarray的个数

另外 Exactly K times = at most K times - at most K - 1 times 是这题的主旨，但是还是得理解上面的subarray的概念

*/

int numberOfSubarrays(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1);
}

int atMost(vector<int>& A, int k) {
    int res = 0, i = 0, n = A.size();
    for (int j = 0; j < n; j++) {
        k -= A[j] % 2;
        while (k < 0)
            k += A[i++] % 2;
        res += j - i + 1;
    }
    return res;
}
