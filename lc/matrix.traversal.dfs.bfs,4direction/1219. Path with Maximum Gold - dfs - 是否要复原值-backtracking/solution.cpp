  /*
  主要的问题是，如何判断这个值是否要复原。
  现在的考虑时，如果问题是找最值，那么从不同地方(不同路径)来到同一点最后产生的结果可能是不一样的。所以每次递归返回时，也要返回它原来的值，以便下一轮的
  其他路径来时用。
  
  相比其他题目，比如迷宫找出口，只要能找到出口就行了，所以这种情况不需要返回：这条路通过这个点没法找到出口，那其他路径通过这个点也不能找到。
  
  但这是只是目前的思考，之后遇到还要再巩固这个想法。
  
  另外一点事这个一维的数组遍历方式挺好的，比二维的要简单 
  */
  
  class Solution {
public:
    vector<int> dir = {0,1,0,-1,0};
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int res =0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                res = max(res,dfs(i,j,grid));         
            }
        }
        return res;
    }
    
    
    int dfs(int row, int col,vector<vector<int>>& grid){
        if(grid[row][col]==0) return 0;
        int res =0, tmp = grid[row][col];
        grid[row][col]=0;
        for(int i =0; i<4; i++){
            int r = row+dir[i], c = col + dir[i+1];
            if(r>=0&&c>=0&&r<grid.size()&&c<grid[0].size()){
                res = max(res,tmp+dfs(r,c,grid));
            }
        }
        grid[row][col] = tmp;
        return res;
    } 
};
