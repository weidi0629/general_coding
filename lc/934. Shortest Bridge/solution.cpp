/*
这题的思路是一个岛屿从边缘开始慢慢的扩张，但是问题是如何实现。
最直接的思路就是bfs（看答案前思考如何实现bfs），下面第二个版本的办法就更直接：每次全局遍历
*/

class Solution {
    public int shortestBridge(int[][] A) {
        int m = A.length, n = A[0].length;
        boolean[][] visited = new boolean[m][n];
        int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        Queue<int[]> q = new LinkedList<>();
        boolean found = false;
        // 1. dfs to find an island, mark it in `visited`
        for (int i = 0; i < m; i++) {
            if (found) {
                break;
            }
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    dfs(A, visited, q, i, j, dirs);
                    found = true;
                    break;
                }
            }
        }
        // 2. bfs to expand this island
        int step = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                int[] cur = q.poll();
                for (int[] dir : dirs) {
                    int i = cur[0] + dir[0];
                    int j = cur[1] + dir[1];
                    if (i >= 0 && j >= 0 && i < m && j < n && !visited[i][j]) {
                        if (A[i][j] == 1) {
                            return step;
                        }
                        q.offer(new int[]{i, j});
                        visited[i][j] = true;
                    }
                }
            }
            step++;
        }
        return -1;
    }
    private void dfs(int[][] A, boolean[][] visited, Queue<int[]> q, int i, int j, int[][] dirs) {
        if (i < 0 || j < 0 || i >= A.length || j >= A[0].length || visited[i][j] || A[i][j] == 0) {
            return;
        }
        visited[i][j] = true;
        q.offer(new int[]{i, j});
        for (int[] dir : dirs) {
            dfs(A, visited, q, i + dir[0], j + dir[1], dirs);
        }
    }
}




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
