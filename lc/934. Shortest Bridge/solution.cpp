class Solution {
public:
    
    int paint(vector<vector<int>>& A, int i, int j){ // 按值传递
        if (i < 0 || j < 0 || i == A.size() || j == A.size() || A[i][j] != 1) return 0;
        A[i][j] = 2; // 标记成2
        return 1 + paint(A,i+1,j) + paint(A,i-1,j) + paint(A,i,j+1) + paint(A,i,j-1) ;
    }
    
    bool expand(vector<vector<int>>& A, int i, int j, int cl){
        if(i<0||j<0||i==A.size()||j==A.size()||A[i][j]!=1) return 0;
        if(A[i][j]==0) A[i][j] = cl+1; // 这里的i,j已经往前走一步了，所以可以直接判断是河还是已经到了
        return A[i][j] == 1;
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        int find =0;
        for(int i=0; find&&i<A.size();i++)
            for(int j=0; !find&&j<A.size();j++)
                find = paint(A,i,j);
        
        for(int cl =2;;cl++)// bfs 每次都从cl出发
            for(int i=0; !find&&i<A.size();i++)
                for(int j=0; !find&&j<A.size();j++){
                    if(A[i][j]==cl&&(expand(A,i+1,j,cl)||expand(A,i-1,j,cl)||expand(A,i,j+1,cl)||expand(A,i,j-1,cl)))
                        return cl-2;
                }
            
    }
};
