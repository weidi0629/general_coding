/*
https://leetcode.com/problems/number-of-corner-rectangles/discuss/110200/Summary-of-three-solutions-based-on-three-different-ideas

dp[i][j][k] ~ 在 0到i-1行， j列与k列都是1的个数。 因为只跟上一行有关，这个3维dp已经压缩过了。

*/

public int countCornerRectangles(int[][] grid) {
    int m = grid.length, n = grid[0].length, res = 0;
    
    int[][] dp = new int[n][n];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) continue;
            
            for (int q = j + 1; q < n; q++) {
                if (grid[i][q] == 0) continue;
                res += dp[j][q]++;
            }
        }
    }  
    return res;
}
