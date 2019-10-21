/*

一维dp表示endtime 为 i 时，最大的profit是多少

如果比现在dp最后一个大，那就更新最后一个。如果还没有之前那个大，那就不要了。因为如果后面继续的话，肯定加前面一个也不加现在这个（如果再来的那个跟前面那个冲突，也肯定跟现在这个冲突）。

注意prev的用法

*/

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }

