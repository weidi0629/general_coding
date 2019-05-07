 vector<int> numMovesStonesII(vector<int>& A) {
        sort(A.begin(), A.end());
        int i = 0, n = A.size(), low = n;
        int high = max(A[n - 1] - n + 2 - A[1], A[n - 2] - A[0] - n + 2);
        for (int j = 0; j < n; ++j) {
            while (A[j] - A[i] >= n) ++i;
            if (j - i + 1 == n - 1 && A[j] - A[i] +1 == n - 1)
                low = min(low, 2);
            else
                low = min(low, n - (j - i + 1));
        }
        return {low, high};
    }
    
    /*
    注意 i 到 j 之间有几个数，是j-i+1
    
    line 4  A[n - 1] - n + 2 - A[1]: 主要的算法，看第一位能移到第二位开始后第一个空格地方吗？
    可以想着把所有的数都靠到 A[n-1]这里去，那最后一个数应该是 A[n-1] - n + 1
    比如 1,2,3,10 -> 7,8,9,10 (10-4 +1), 但这里第一位不算，所以要再加1. 然后算倒数第二位减去第二位，算从第二位开始有几个空格
    
    line 7 - 8: 
    是个corner case 
    For case 1,2,3,4,10, 因为最两端的点不能移到两端
    2 move needed from 1 to 6, then from 10 to 5.
    
    line 7-8表示连续的点，这个举得栗子
    
    
    appendix 
    leetcode上解释line4 
    The first step(as in each step) has to be moving rightmost or leftmost stone.
Starting the second step, the optimal way is to increment leftmost or decrement rightmost by ONE for each move.
To do so, we need two OR MORE adjacent stones that contain either the leftmost or the rightmost stone. e.g. [1,2,3,4,10] ->[2,3,4,5,10]->[3,4,5,6,10] ...
In the first step, we need to move leftmost or rightmost stone to somewhere that could form this adjacent structure.
To move A[0], it hasn't to be A[1]+1 since that may have already been occupied. So move A[0] to the first unoccupied slot to the right of A[1]. e.g[1,4,5,6,10]->[4,5,6,7,10]. It's certainly possible that no such slot exists when A[1]~A[n-1] are adjacent. That means we cannot move A[0]. If neither A[0] or A[n-1] is movable, the answer is 0.
Therefore, the unoccupied slots between A[1] and A[n-1] OR A[0] and A[n-2] are the maximum steps to move.
    */
