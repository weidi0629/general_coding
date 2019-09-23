/*

这题需要知道的几点：

1 union find: 每一条只要联通的的路，怎么样交换都可以从小排到大的，所以要把每条路子给找出来，union find是最好的办法

2 index manipulation, 这是自己考虑时没有想到的。只要用index去交换就可以了 


*/

int find(vector<int>& ds, int i) {
  return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
  vector<int> ds(s.size(), -1);
  vector<vector<int>> m(s.size());
  
  // 每个union find都要做的 
  for (auto& p : pairs) {
    auto i = find(ds, p[0]), j = find(ds, p[1]);
    if (i != j) ds[j] = i;
  }
  
  // 根据跟一组压index 
  for (auto i = 0; i < s.size(); ++i) m[find(ds, i)].push_back(i);
  
  for (auto ids : m) {
    string ss = "";
    for (auto id : ids) ss += s[id]; //抓出来的都是一组里的，组内排序
    sort(begin(ss), end(ss));
    for (auto i = 0; i < ids.size(); ++i) s[ids[i]] = ss[i]; // 这步index排序是最漂亮的， ids[i]里压的都是index
  }
  return s;
}
