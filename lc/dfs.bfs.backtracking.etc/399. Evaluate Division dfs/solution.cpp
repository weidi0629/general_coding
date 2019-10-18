class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        //保存的是 i -> j 他们的之间的valule 
        unordered_map<string, unordered_map<string,double>> m;
        for(int i=0; i< values.size(); i++){
            m[equations[i].first].insert(equations[i].second,values[i]); //注意定义的方法
            if(values[i])
                m[equations[i].second].insert(equations[i].first,1/values[i]);           
        }
        unordered_set<string> s;
        vector<double> res;
        for(auto q:query){
            double tmp = dfs(q.first,q.second,m,s);
            if(tmp) res.push_back(tmp);
            else res.push_back(-1.0);
        }
        return res;
    }
    
    double bfs(string start, string end, unordered_map<string, unordered_map<string,double>> m,  unordered_set<string>& s){
        if(m[start].find[end]!=m[start].end)
            return m[start][end];
        else if(s.find(end) == s.end){ // 没找到,并且没来过
            for(auto st:m[start]){ // 每个st是以第二个点位key的map
                s.insert(st)
                double tmp = dfs(st,end,m,s);
                if(tmp)
                    return tmp*st.second; //如果找到了，那递归返回时会一层层乘上去
            }
        }
        return 0;
    }
};
