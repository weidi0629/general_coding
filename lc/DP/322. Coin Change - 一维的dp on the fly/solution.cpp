/*
可以从二维做起然后优化  
dp[i][j] //dp[i][j] i: amount, index  到目前j个coins为止多少能取得amount的最小的coin数

从下面这段自己做的可以看到，其实j是可以压缩成一位的，根本没有用到，后面那个是答案

int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount, vector<int>{INT_MAX});
        dp[0][0] = 0; //dp[i][j] i: amount, index                      
        for(int i=0; i<amount; i++){
            for(int j=0; j<coins.size();j++){
                if(i>coins[j])
                    dp[i][j] = min(dp[i][j],dp[i-coins[j]][j]+1);
            }
        }
        int res;
        for(int i=0; i<coins.size();i++){
            res = min(res,dp[amount][i]);
        }
        return -1;
    }
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
