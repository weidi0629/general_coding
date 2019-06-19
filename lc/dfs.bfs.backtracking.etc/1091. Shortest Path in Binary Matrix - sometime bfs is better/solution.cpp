int shortestPathBinaryMatrix(vector<vector<int>>& g, int steps = 0) {
  queue<pair<int, int>> q;
  q.push({ 0, 0 });
  while (!q.empty()) {  // 注意这个两个 while的操作
    ++steps;
    queue<pair<int, int>> q1;
    while (!q.empty()) {
      auto c = q.front();
      q.pop();
      if (c.first >= 0 && c.second >= 0 && c.first < g.size() && c.second < g.size() && !g[c.first][c.second]) {
        g[c.first][c.second] = 1; // 之后就不要再看了，这点重要
        if (c.first == g.size() - 1 && c.second == g.size() - 1) return steps;
        for (auto i = -1; i < 2; ++i) // good way to 遍历所有的方向
          for (auto j = -1; j < 2; ++j)
            if (i != 0 || j != 0) q1.push({ c.first + i, c.second + j });
      }
    }
    swap(q, q1); // 记住swap这个用法
  }
  return -1;
}
