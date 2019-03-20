class Solution {
public:
    string crackSafe(int n, int k) {
        int total = pow(n,k); //总共的亮
        string s{n,0};
        unordered_set<string> visited;
        visited.insert(s);
        dfs(s,visited,n,k,total);
        return s;
    }
    
    bool dfs(string& s, unordered_set<string> visited,int n, int k,int total){
        if(visited.size()==total) return true;
        string prev = s.substr(s.size()-n+1); // 比n少一位      
        for(int i=0;i<k;i++){ //begin the backtracking
            if(visited.find(prev+to_string(i))!=visited.end()){ //之前没有过
                visited.insert(prev+to_string(i));
                s = s+to_string(i);
                if(dfs(s,visited,n,k,total)) return true;
                //没有找到，归位，因为这个数在别人的round里也可能需要
                //注意所有的可能性都要查，所以参数没有向前，回到最原始的位数
                else
                {
                    s = s.substr(0,s.size()-1);
                    visited.erase(prev+to_string(i));
                }
            }
        }
        return false; // 这句漏掉了
    }
};
