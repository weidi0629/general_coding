/*
dp[i][j] i city, j week, dp valule means max vacation day i can get

这题自己做的时候，唯一的大错误就是没有想到len是什么： len是week， 每个week在里面搞

*/

class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        
        if(days == null || days.length == 0 || flights == null || flights.length == 0
          || days[0].length == 0 || flights[0].length == 0) return 0;
        
        int n = days.length, k = days[0].length;
        int[][] dp = new int[n][k];
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < k; j ++) {
                dp[i][j] = -1;
            }
        }
        dp[0][0] = days[0][0];
        for(int i = 1; i < n; i ++) {
            if(flights[0][i] == 1) dp[i][0] = days[i][0];
        }
        
        for(int week = 1; week < k; week ++) {
            for(int dest = 0; dest < n; dest ++) {
                for(int depart = 0; depart < n; depart ++) {
                    if(dp[depart][week - 1] != -1 && (flights[depart][dest] == 1 || depart == dest)) {
                        dp[dest][week] = Math.max(dp[dest][week], dp[depart][week - 1] + days[dest][week]);
                    }
                }
            }
        }
        
        int res = 0;
        for(int city = 0; city < n; city ++) {
            if(dp[city][k - 1] > res) res = dp[city][k - 1];
        }
        return res;
    }
}
