class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60);
        int res =0;
        for(auto t:time){
            res+= count[(60-t%60)%60]; //注意后面一个 %60是为了能被60整除的数
            count[t%60]++;
        }
        return res;
    }
};
