/*
这题主要是一个status的表示。 queue里三个参数，前两个是蛇尾的位置，最后一个是他的status，false是horizental， true是vertical。

只考虑蛇尾那一个格子，不考虑蛇头

同一个格子蛇尾经过，需要check他的status，他可能是横着过来的，也可能是竖着过来的

一般这种问题要搞个visited 数组之类的，这题直接用它原来的grid。 设定他是2还是4来表示是横着过来还是竖着过来
*/

bool canRotate(vector<vector<int>>& g, int i, int j) {
  // 根据下面所说的，
  return i < g.size() - 1 && j < g[i].size() - 1
    && (g[i + 1][j] & 1) == 0 && (g[i][j + 1] & 1) == 0 && (g[i + 1][j + 1] & 1) == 0;
}
bool canGoDown(vector<vector<int>>& g, int i, int j, bool vertical) {
  if (vertical) return i < g.size() - 2 && (g[i + 2][j] & 1) == 0;
  return i < g.size() - 1 && (g[i + 1][j] & 1) == 0 && (g[i + 1][j + 1] & 1) == 0;
}
bool canGoRight(vector<vector<int>>& g, int i, int j, bool vertical) {
  if (!vertical) return j < g[i].size() - 2 && (g[i][j + 2] & 1) == 0;
  return j < g[i].size() - 1 && (g[i][j + 1] & 1) == 0 && (g[i + 1][j + 1] & 1) == 0;
}
int minimumMoves(vector<vector<int>>& grid, int steps = 0) {
  queue<array<int, 3>> q1, q2;
  q1.push({ 0, 0, false }); // not vertical.
  while (!q1.empty()) {
    while (!q1.empty()) { // 这个地方也可用 for(queue.size()) 来做，
      auto& a = q1.front();
      if (a[0] == grid.size() - 1 && a[1] == grid[a[0]].size() - 2) return steps;
      if ((grid[a[0]][a[1]] & (a[2] ? 2 : 4)) == 0) { // 这是最重要的两句， 110表示以两个状态
        // 用2,4因为第一位0要给他空出来。就算来过了，不能直接赋1，以为之后rotate之类的还要用到这个格子
        grid[a[0]][a[1]] = grid[a[0]][a[1]] | (a[2] ? 2 : 4);
        if (canGoDown(grid, a[0], a[1], a[2])) q2.push({ a[0] + 1, a[1], a[2] });
        if (canGoRight(grid, a[0], a[1], a[2])) q2.push({ a[0], a[1] + 1, a[2] });
        if (canRotate(grid, a[0], a[1])) q2.push({ a[0], a[1], a[2] ? false : true });// rotate: 蛇尾不变，但状态flip
      }
      q1.pop();// 最终q1会给掏空
    }
    ++steps;
    swap(q1, q2);
  }
  return -1;
}
