class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    vector<vector<int>> g;
    int vst[201][201], id; //也可以搞成一维的
    int n, m;
		
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        n = grid.size(),m = grid[0].size();
        g.swap(grid); // move operation, for performance
        vector<int> ret;
        for(auto h:hits){
            int r = h[0], c = h[1];
            int removal = 0;
            if(g[r][c] == 1){
                g[r][c] = 0;
                for(int d = 0;d<4;d++){
                    int x = r+dr[d],y = c + dc[d];
                    if (!valid(x, y) || !g[x][y]) continue; //考虑哪个情况不用调查：1 invalid position 2 已经是0了
                    ++id; //mark each connecting parts with a unique id in this run
                    if(falling(x,y)) removal += cnt(x,y); //注意如果这个位置要掉，跟他相连的一整块（递归的一整块）都要掉
                                                            （否则它四面都是墙或者延伸出去的某个点已经有连着天花板）
                }
            }
            ret.push_back(removal);
        }
        return ret;
    }
    
    bool falling(int r,int c){
        if(!valid(r,c)||!g[r][c]) return true; //一直到出界了都没有能找到靠山，所以return true
        if (vst[r][c] == id) return true; //本来想靠别人，结果又回到自己，所以谁都靠不了，return true
        if (r == 0) return false; //connecting 1st row
        vst[r][c] = id;
        for (int d = 0; d < 4; ++d){ // 这个是递归的找，只有一个方向（延伸出去）不掉下来，他就不会掉下来。反过来说，如果四个方向都要掉，
                                        那跟他连着的一整块（递归的一整块）都是要掉的。 
            if (!falling(r + dr[d], c + dc[d])) return false;
        } 
        return true;
    }
    int cnt(int r,int c){ //因为已经是确认一整块都要掉，就放心的递归计数了
        if (!valid(r,c)||!g[r][c]) return 0;
        int ret = 1;
        g[r][c] = 0;
        for(int d = 0; d < 4; ++d){
            ret += cnt(r + dr[d], c + dc[d]);
        }
        return ret;
    }
    bool valid(int r,int c){
        return 0 <= r && r < n && 0 <= c && c < m;
    }
};
