/*
固定两行，取 Cn,2
*/
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res =0;
        for(int i=0; i<m; i++)
            for(int j=i+1; j<m;j++){
                int tmp = 0;
                for(int k =0;k<n;k++){
                    tmp += grid[i][k]&grid[j][k];
                }
                res+=tmp*(tmp-1)/2;  // Cn2 的公式
            }
        return res;  
    }
};
