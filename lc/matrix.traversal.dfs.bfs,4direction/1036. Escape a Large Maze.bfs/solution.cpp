bool bfs(unordered_set<long long> &visited, vector<int>& s, vector<int>& t, int blocks) {
  vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
  vector<pair<int, int>> q = { {s[0], s[1]} };
  while (!q.empty() && q.size() <= blocks) {
    vector<pair<int, int>> q1;
    for (auto p : q) {
      for (auto d : dirs) {
        auto x = p.first + d[0], y = p.second + d[1];
        if (x < 0 || x > 999999 || y < 0 || y > 999999) continue;
        if (x == t[0] && y == t[1]) return true;
        if (visited.insert(((long long)x << 32) + y).second) q1.push_back({ x, y }); //可以直接用insert判断是否有重复
      }
    }
    swap(q, q1); // 注意这个swap用法
  }
  return !q.empty();
}
bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& s, vector<int>& t) {
  unordered_set<long long> visited;
  for (auto b : blocked) visited.insert(((long long)b[0] << 32) + b[1]);  //化为1维数组
  return bfs(visited, s, t, blocked.size()) && bfs(visited, t, s, blocked.size());
}
