/*
1. dp[i][j] max days we can get in city i of week j, if there is flight
2. 写代码时可以从dp公式开始写
3. 这个版本是倒过来的，方便最后的找答案

*/

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int nc = days.size(), nw = days[0].size(); // # of city, # of weeks  
        vector<vector<int>> dp(nw,vector<int>(nc,-1));
        
        for(int j=nc-1;j>0;j++) // 从最后一个city开始，方便这次寻找结束后找到最终答案    
            for(int i=0;i<nc;i++){ // i跟i1是要组成一个完整的二维数组的遍历
                dp[i][j] = days[i][j];
                for(int i1=0;i1<nc&&j<nc-1;i1++)
                    if(flights[i1][i]||i1==i) // 呆在那个city不走了
                        dp[i][j] = max(dp[i][j],dp[i1][j+1]+days[i][j]);
            }
        /*最后这把寻找完全错了
        int res = -1;
        for(int i=0;i<nw;i++) //这是我们倒过来寻找的原因，只要遍历city0那一行就可以了
            if(dp[0][i]>res) res = dp[0][i];*/
        
        int res = dp[0][0]; // 有可能在第一个city就不走了
        for(int i=0; i<nc; i++){ // 遍历所有的CITY
            if(flights[0][i])
                res = max(res,dp[i][0]); //第一个礼拜一就从city0飞走了
        }
        return res;
    }
};
