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
