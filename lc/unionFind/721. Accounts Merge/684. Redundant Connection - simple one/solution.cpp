class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(2001), res;
        iota(p.begin(),p.end(),0);
        for(auto e:edges){
            int a=find(e[0],p), b=find(e[1],p);
            if(a==b){
                return e;
            }else{
                p[a] = b;
            }
        }
        return {};
    }
    
    int find(int i, vector<int>& p){
        if(i!=p[i])
            return find(p[i],p);
        return i;
    }
    
};

// this tree won't be a fat tree
class Solution {  
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(edges.size(),0);
        for(int i=0;i<p.size();i++) p[i]=i;  // every node's parent is itself at first
        for(auto e:edges){
            int m=e[0],n=e[1];
            while(m!=p[m]) m=p[m]; // keep looking its highest parent
            while(n!=p[n]) n=p[n]; // keep looking its highest parent
            if(n==m) return e;
            else p[n] = p[m]; // undirected graph, no matter who is whose fater
        }
        return {};
    }
};
