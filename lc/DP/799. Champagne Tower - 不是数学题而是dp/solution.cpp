/*
不要想着数学公式，就是按题意直接下来，非常straightforward
*/

double champagneTower(int poured, int query_row, int query_glass) {
        double result[101][101] = {0.0};
        result[0][0] = poured;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j <= i; j++) {
                if (result[i][j] >= 1) {
                    result[i + 1][j] += (result[i][j] - 1) / 2.0;
                    result[i + 1][j + 1] += (result[i][j] - 1) / 2.0;
                    result[i][j] = 1;
                }
            }
        }
        return result[query_row][query_glass];
    }
    
    
    // O(1)space
    
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> res(102);
        res[0] = poured;
        for (int row = 1; row <= query_row; row++)
            for (int i = row; i >= 0; i--)
                res[i + 1] += res[i] = max(0.0, (res[i] - 1) / 2); //上一行给下面的左边右边赋值 
        return min(res[query_glass], 1.0);
    }
    
    
    
