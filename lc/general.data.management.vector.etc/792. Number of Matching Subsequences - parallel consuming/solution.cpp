class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0;
        unordered_map<char,vector<string>> m;
        for(auto w:words){
            m[w.back()].push_back(w);
        }      
        for(int i=S.size()-1; i>=0; i--){
            auto bucket = m[S[i]];
            m[S[i]].clear(); // 注意map clear的用法
            for(auto s:bucket){
                s.pop_back();
                if(s.empty())
                    res++;
                else{
                    m[s.back()].push_back(s);
                }
            }
        }
        return res;
    }
};
