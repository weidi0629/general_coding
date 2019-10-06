/*
 之前一直纠结的，如果有重复的怎么办。
 在这个答案中，每次找map里的值，这些值都是以前的，也就是说是之前经过的，subsequence的顺序被保留起来，所以不会有问题。而之前那个值也是这么来的--dp的
 特性。
*/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> mp;
        int res =1;
        for(auto a:arr){
            mp[a] = max(mp[a],1+mp[a-diff]);
            res = max(res,mp[a]);
        }
        return res;
    }
};
