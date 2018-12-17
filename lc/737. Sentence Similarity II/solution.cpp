/*
1. 用pair来建立树
2. word来测试true and false
*/

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string,string> mp;
        for(auto p:pairs){  // step1, pair建立树
            /*string p1=p.first, p2 = p.second;
            //if(find(mp, mp[p1])!=find(mp, mp[p2]))
            if(find(mp, p1)!=find(mp, p2))
                mp[p2] = mp[p1]; //*/
            string parent1 = find(mp, p.first), parent2 = find(mp, p.second); // 注意，先找爸爸，爸爸不一样，爸爸赋爸爸
            if (parent1 != parent2) mp[parent1] = parent2;
        }
        
        for(int i=0;i<words1.size();i++){//step 2, 测试
            string w1=words1[i], w2 = words2[i];
            if(w1!=w2&&find(mp,w1)!=find(mp,w2))
                return false;
        }
        return true;
    }
    
    string find(unordered_map<string,string> mp,string s){ // 标准的union find 
        //if(mp[s]!=s)
          //  mp[s] = find(mp,mp[s]);
        //return mp[s];
         return !mp.count(s) ? mp[s] = s : (mp[s] == s ? s : find(mp, mp[s]));
    }
};
