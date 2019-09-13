/*
using lambda function 
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(auto w : words){
            freq[w]++;
        }
        
        auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        typedef priority_queue< pair<string,int>, vector<pair<string,int>>, decltype(comp) > my_priority_queue_t;
        my_priority_queue_t  pq(comp);
        
        for(auto w : freq ){
            pq.emplace(w.first, w.second);
            if(pq.size()>k) pq.pop();
        }
        
        vector<string> output;
        while(!pq.empty()){
            output.insert(output.begin(), pq.top().first);
            pq.pop();
        }
        return output;
    }
};



/*
using structure 
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto w: words)
            mp[w]++;
        
        priority_queue<pair(string, int),vector<pair(string, int)>,comp> pq;
        
        for(auto m:mp){
            pq.insert(m);
            if(pq.size()>k)
                pq.pop();
        }
        vector<string> res;
        while(!pq.empty()){
            res.emplace_back(pq.top().first);
            qp.pop();
        }
        return res;
    }
    
private:
    struct comp{
        comp();
        ~comp();
        bool operator(const pair(string, int) a, const pair(string, int) b)()const{
            return a.second>b.second || a.first < b.first;
        }
    }
};
