/*
因为一个node 最多3个neighbor， 所以肯定是有花可以选的。用准备return的res数组代表某个node已经使用的花的种类，来决定当前node的的种类
*/

vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
  vector<int> res(N);
  vector<vector<int>> g(N);
  for (auto p : paths) { //构图
    g[p[0] - 1].push_back(p[1] - 1);
    g[p[1] - 1].push_back(p[0] - 1);
  }
  for (auto i = 0; i < N; ++i) {
    bool used[5] = {};  // 用0来代表还没有选  
    for (auto j : g[i]) used[res[j]] = true; // 直接使用res，greedy
    for (auto fl = 1; fl <= 4; ++fl) {
      if (!used[fl]) res[i] = fl;
    }
  }
  return res;
}
