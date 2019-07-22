class Solution {
    vector<vector<int>> nodeEdges;
    vector<int> dist;
    
    void buildGraphEdges(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        nodeEdges.resize(2*n, vector<int>());
        for (auto e: red_edges) {
            nodeEdges[e[0] * 2 + 1].push_back(e[1] * 2 + 0); // 奇数只能翻到偶数，偶数只能翻到奇数 
        }
        for (auto e: blue_edges) {
            nodeEdges[e[0] * 2 + 0].push_back(e[1] * 2 + 1);
        }
    }
    
    void bfs(int n, int startNode) {
        queue<int> bfsQ;
        bfsQ.push(startNode);
        vector<bool> inQ(2*n, false);
        inQ[startNode] = true;
        int count = 0;
        while (!bfsQ.empty()) {
            int size = bfsQ.size();
            for (int i = 0; i < size; ++i) {  // 这个for循环是必要的，只有过了这一轮，count才能加1 
                int node = bfsQ.front(); bfsQ.pop();
                dist[node/2] = min(dist[node/2], count);
                for (auto next: nodeEdges[node]) {
                    if (!inQ[next]) {
                        bfsQ.push(next);
                        inQ[next] = true;
                    }
                }
            }
            count ++;
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        buildGraphEdges(n, red_edges, blue_edges);
        dist.resize(n, INT_MAX);
        dist[0] = 0;
        bfs(n, 0);
        bfs(n, 1);
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};
