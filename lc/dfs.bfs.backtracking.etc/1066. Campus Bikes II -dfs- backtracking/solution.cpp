class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<bool> visited(bikes.size(), false);
        backtracking(workers, bikes, visited, 0, 0);
        return global_minimum;
    }
    
    int global_minimum = numeric_limits<int>::max();
    void backtracking(const vector<vector<int>>& workers, const vector<vector<int>>& bikes, vector<bool> visited, int local_distance, int step) {
        if (step == workers.size()) {
            global_minimum = min(global_minimum, local_distance);
            return;
        }
        if (local_distance >= global_minimum)
            return;
        for (int i = 0; i < visited.size(); ++i) {
            if (visited[i])
                continue;
            visited[i] = true;
            backtracking(workers, bikes, visited, local_distance + abs(workers[step][0] - bikes[i][0]) + abs(workers[step][1] - bikes[i][1]), step + 1);
            visited[i] = false;
        }
    }
};
