/*
这题关键是转换问题成 knapsacks, 最大的weight是总重量的一半, 看能多接近总重量的一般。

*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int S=0, s2 = 0;
        int n = stones.size();
        for(auto s:stones) S +=s;
        vector<vector<bool>> dp = {S+1,vector<bool>(n+1,false)};
        for(int i=0; i<n; i++){
            dp[0][i] = true;
        }
        for(int s=1; s<=S/2; s++) // knapsack, 最大的weight是总重量的一半 
            for(int i=1; i<=n; i++){
                if(dp[s][i-1]||i-stones[i-1]>0&&dp[i-stones[i-1]][i-1]){
                    dp[s][i] = true; // 这里的i处理的是 i-1之前的事情
                    s2 = max(s2,s);
                }
            }
        return S - 2*s2;
    }
};
