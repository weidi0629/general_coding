/*

这题有点像dp. 要点是从两个方向处理：
首先是maxL, 从左边往右边方向， maxL[i] 意味着到i为止，长度为L的sum最大值

maxR是一个意思，倒过来找，因为maxL已经处理过了，保证是最大的值    ----><----  

要看懂这个再看后面四眼的方法 
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
