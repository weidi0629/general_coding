/*
这题没有思路非常不应该，如果这次打开是复习，请再看题意再次想一下解题思路

有两种dp的办法： 
1.
题目类似排列组合，能形成的结果非常多，应该要想到dfs，backtracking

然后应该想到细节的是跟之前的关系（也就是传递进来的参数）： 一个是当前有几个骰子了（题设要n，这个参数肯定要的），题设有两个点的limit，那之前进来的
哪个点也是要的，还有它的长度也是要的。之后就可以想到，如果当前点跟之前的点不是一个，那就长度重新开始（一条新的分支），如果一样，长度加1进去。

最后要想到memorization

https://leetcode.com/problems/dice-roll-simulation/discuss/403819/DFS-%2B-Memorization-Short-and-Simple

*/

int ans = 0;
    
    public int dieSimulator(int n, int[] rollMax) {
        dfs(n, rollMax, -1, 0);
        return ans;
    }
    
	// dieLeft : the number of dies
	// last : last number we rolled
	// curlen : current len of same number
	// This function trys to traval all the valid permutation
    private void dfs(int dieLeft, int[] rollMax, int last, int curlen){
        if(dieLeft == 0){
            ans++;
            return;
        }
        for(int i=0; i<6; i++){
            if(i == last && curlen == rollMax[i]) continue;
            dfs(dieLeft - 1, rollMax, i, i == last ? curlen + 1 : 1);
        }
    }
But this will be TLE. So we add memorization:

    int[][][] dp = new int[5000][6][16];
    final int M = 1000000007;
    
    public int dieSimulator(int n, int[] rollMax) {
        return dfs(n, rollMax, -1, 0);
    }
    
    private int dfs(int dieLeft, int[] rollMax, int last, int curlen){
        if(dieLeft == 0) return 1;
        if(last >= 0 && dp[dieLeft][last][curlen] > 0) return dp[dieLeft][last][curlen];
        int ans = 0;
        for(int i=0; i<6; i++){
            if(i == last && curlen == rollMax[i]) continue;
            ans = (ans + dfs(dieLeft - 1, rollMax, i, i == last ? curlen + 1 : 1)) % M;
        }
        if(last >= 0) dp[dieLeft][last][curlen] = ans;
        return ans;
    }

/*
第二种方法
/*
 dp[i][j] i: 到目前为止筛子丢了几次了， j这次停在哪个点
 
 跟之前的关系：例如1的limit是3
 
 比如 axxb， b丢到1，那么我们要保证的 a11没有，也就是211,311,411 ...  911, 那不是就这八种呢。 不是的，你要计算的有多少种方法到a，而且a不能是1，不然就已经超限了。
 
 用的办法是  sum[i-1][1] - sum[i-limi[1]][2-9] = sum[i-1][1] - (sum[i-limi[1]][6] - sum[i-limi[1]][1])
 
 如果正好长度是limi，只要减去一个就行了，就是 111这种情况 
 
 还有一点是sum在增加，所以每次筛子（n向前），内部遍历0-6之后，要找个地方存sum，我们就存在 dp[i][6]里了
 
*/

class Solution {
    public int dieSimulator(int n, int[] rollMax) {
        int mod = (int)1e9 + 7;
        //dp[i][j] represents the number of distinct sequences that can be obtained when rolling i times and ending with j
        //The one more row represents the total sequences when rolling i times
        int[][] dp = new int[n + 1][7];
        //init for the first roll
        for (int i = 0; i < 6; i++) {
            dp[1][i] = 1;
        }
        dp[1][6] = 6;
        for (int i = 2; i <= n; i++) {
            int total = 0;
            for (int j = 0; j < 6; j++) {
                //If there are no constraints, the total sequences ending with j should be the total sequences from preious rolling
                dp[i][j] = dp[i - 1][6];
                //For xx1, only 111 is not allowed, so we only need to remove 1 sequence from previous sum
                if (i - rollMax[j] == 1) {
                    dp[i][j]--;
                }
                if (i - rollMax[j] >= 2) {
                    int reduciton = dp[i - rollMax[j] - 1][6] - dp[i - rollMax[j] - 1][j];
                    //must add one more mod because subtraction may introduce negative numbers
                    dp[i][j] = ((dp[i][j] - reduciton) % mod + mod) % mod;
                }
                total = (total + dp[i][j]) % mod;
            }
            dp[i][6] = total;
        }
        return dp[n][6];
    }
}

