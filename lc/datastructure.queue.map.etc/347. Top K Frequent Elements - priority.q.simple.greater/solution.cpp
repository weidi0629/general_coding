class Solution {
public:   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(auto num:nums){ // key - times
            mp[num]++;
        }
        
        for(auto m:mp){
            q.push(make_pair(m.second,m.first)); // put time first, to compare
            while(q.size()>k) q.pop();
        }
        while(!q.empty()){
            auto v = q.top();
            res.push_back(v.second);
            q.pop();
        }
        return res;
    }
};
