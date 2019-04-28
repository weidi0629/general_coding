class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](const vector<int> &a,const vector<int> &b){
            return a[0]-b[0]<a[1]-b[1];
        });
        int res =0, n = costs.size();
        for(int i=0; i<n/2; i++){
            res = res+ costs[i][0]+ costs[i+n/2][1];
        }
        return res;
    }
};
