/*
Dijkstra, 永远是从大的值开始行动： 比如走到了一个错的死胡同，priority_queue make sure 回到之前最optimize的点重新出发。 

注意代码里几个比较好的用法
*/

int maximumMinimumPath(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        static constexpr int DIRS[][2] = {{0,1},{1,0},{0,-1},{-1,0}}; // 二维数组的定义方法，constexpr的用法
        priority_queue<pair<int,pair<int,int>>> pq; // priority_queue里面组合的用法
        pq.emplace(A[0][0], make_pair(0, 0));
        int maxscore = A[0][0];
        A[0][0] = -1; // visited
        while(!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            maxscore = min(maxscore, f.first);
            if(f.second.first == n - 1 && f.second.second == m - 1)
                return maxscore;
            for(const auto& d : DIRS)
            {
                int newi = d[0] + f.second.first, newj = d[1] + f.second.second;
                if(newi >= 0 && newi < n && newj >= 0 && newj < m && A[newi][newj]>=0)
                {
                    pq.emplace(A[newi][newj], make_pair(newi, newj)); //插入时不需要在外面make_pair 
                    A[newi][newj] = -1;
                }
            }
        }
        return -1; // shouldn't get here
    }
