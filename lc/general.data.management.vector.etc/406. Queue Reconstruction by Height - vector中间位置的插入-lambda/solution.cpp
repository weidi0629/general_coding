/*
按height先分组，在同样的height内部用第二个参数小到大排序。
然后第二个组进来时，按第二位插入：小的不影响大的第二个参数，但已经插入的会是决定这个值插哪里。

两种插入lambda模式
*/

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(),[](pair<int,int> p1, pair<int,int> p2){
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
        vector<pair<int,int>> sol;
        for (auto person : people){
            sol.insert(sol.begin() + person.second, person);
        }
        return sol;
    }
    
    
 vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
                    { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
    sort(people.begin(), people.end(), comp);
    vector<pair<int, int>> res;
    for (auto& p : people) 
        res.insert(res.begin() + p.second, p);
    return res;
}
