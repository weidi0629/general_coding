/*

这题有点像dp. 要点是从两个方向处理：
首先是maxL, 从左边往右边方向， maxL[i] 意味着到i为止，长度为L的sum最大值

maxR是一个意思，倒过来找，因为maxL已经处理过了，保证是最大的值    ----><----  

要看懂这个再看后面那种方法 

*/

class Solution {
public:
    
    int res = INT_MIN;
    
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        return max(helper(A,L,M),helper(A,M,L));
    }
    
    int helper(vector<int> A, int L, int M){
        // left to right. last L. including i.
        int n = A.size();
        vector<int> sumL(n);
        vector<int> maxL(n);
        sumL[0] = A[0];
        maxL[0] = A[0];
        for (int i = 1; i < n; i++)
        {
            // sumL[i-1] + A[i] - A[i-L]
            sumL[i] = sumL[i-1] + A[i] - (i >= L ? A[i-L] : 0);
            maxL[i] = max(sumL[i], maxL[i-1]);
        }

        // right to left. next M. starting i+1.
        vector<int> sumM(n);
        vector<int> maxM(n);
        sumM[n-1] = 0;
        maxM[n-1] = 0;
        int res = maxL[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            
            sumM[i] = sumM[i+1] + A[i+1] - (i+M+1 < n ? A[i+M+1] : 0);
            
            maxM[i] = max(sumM[i], maxM[i+1]);
            
            //Avoid another loop
            res = res < maxM[i] + maxL[i] ? maxM[i] + maxL[i] : res;
        }
        
        return res;
    }
    
};

/*
here Lee combined two rounds into 1 pass, genius move as always. And actually here, the traversal is even more straightforward:
i is the current position, lmax is the max subarray value whose length is L till the point i-M, you can think it as dp[i-M] or whatever, 
using this to get the case when L is before M, then make another order at meantime.

---------------------------- len == M
|_________________________|______________|
0-------------------------lmax---------- i

*/

int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        for (int i = 1; i < A.size(); ++i)
            A[i] += A[i - 1];
        int res = A[L + M - 1], Lmax = A[L - 1], Mmax = A[M - 1];
        for (int i = L + M; i < A.size(); ++i) {
            Lmax = max(Lmax, A[i - M] - A[i - L - M]); // 倒过来看，从 i-L-M 到 i-M,求的是这段紧贴M的值 |___...___|___L___|___M___|i
            Mmax = max(Mmax, A[i - L] - A[i - L - M]);
            res = max(res, max(Lmax + A[i] - A[i - M], Mmax + A[i] - A[i - L]));
        }
        return res;
    }










