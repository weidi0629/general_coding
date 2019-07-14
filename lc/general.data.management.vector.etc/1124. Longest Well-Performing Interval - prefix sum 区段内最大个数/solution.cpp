/*
这题主要是2点，代码内有标注
1. 如果score是>0, 说明从零到目前为止都是可以的--不管里面怎么样，结果是>0的就好

2. 以为要保证score至少大于0. score 减去 score-1  == 1， 肯定是大于0的。用一个map来维护index

*/

int longestWPI(vector<int>& hours) {
        int res = 0, score = 0, n = hours.size();
        unordered_map<int, int> seen = {{0, -1}};
        for (int i = 0; i < n; ++i) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {   //  * 1
                res = i + 1;
            } else {
                if (seen.find(score) == seen.end())
                    seen[score] = i;
                if (seen.find(score - 1) != seen.end())  // *2
                    res = max(res, i - seen[score - 1]);
            }
        }
        return res;
    }
