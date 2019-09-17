/*
这题其实问的是，不同的路线，每条路线只能走M步，最后能cover的点数。这题并不是找什么优化的路线，而只是找一个办法，把每条不同的路走一遍以后最后能cover的点数
那跟dijkstra有什么关系呢，考虑下面这张图，我们要计算右下角这个点往左边还能走几步，那肯定是从最上面那天路线上来的，因为中间那条线路过来已经没有剩余的点了。 那如何在最后统计的时候知道右下角这个点剩余的点应该用上面那条路线剩余的点呢，就要用到dijkstra了。
也就是说，遍历所有的点的同时，保证每个点剩余的步数是最多的。
然后结合代码里的comment就很清楚了。

结合google doc里的解释，这里不好贴图
*/

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        priority_queue<pair<int,int>> q; // <move left, index>
        unordered_map<int,unordered_map<int,int>> g; // e1 e2 nodes
        unordered_map<int, int> seen; // how many left at index i 
        // contruct a graph
        for(auto e:edges){
            g[e[0]][e[1]] = g[e[1]][e[0]] = e[2];
        }
        q.push(make_pair(M,0));

        while(!q.empty()){
            auto i = q.top();
            q.pop();
            int move = i.first, iidx = i.second;
            // 永远是剩余步数最多的点先说话。注意，就算进入queue也不一定就进seen，有可能同样点通过不同的路线都进queue，但剩余步数多的情况先
            // 说话
            if(!seen.count(iidx)){
                seen[iidx] = move;
                for(auto j:g[iidx]){
                    int jidx = j.first;
                    auto wt = g[iidx][jidx];
                    int newmove = move- wt-1;
                    if(!seen.count(jidx)&&newmove >=0)
                        q.push({newmove, jidx});
                }
            }
        }
        int res=seen.size();
        for(auto e:edges){
            int a = seen.find(e[0]) == seen.end()?0:seen[e[0]];
            int b = seen.find(e[1]) == seen.end()?0:seen[e[1]];
            res += min(a+b, e[2]); // 这是处理例图中最后一条没有连起来的线路的情况
        } 
        return res;
    }
};
