class Solution {
public:
    vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0;i<parent.size();i++)
            parent.push_back(i);  // every node's parent is itself at first
        for(auto e:edges){
            int v0=e[0],v1=e[1];
            if(find(v0)==find(v1))  // has the same root, found it!
                return e;
            //parent[find(v0)] = parent[find(v1)]; // 这里错了,右边不需要parent
            else
                parent[find(v0)] = find(v1); // setting the parent，给它再升一级
        }
        return {};
    }
    
    int find(int v){  // this would create a fat tree
        if(v!=parent[v]) // is not itself, 已经被人搞过了
            parent[v]=find(parent[v]);
        return parent[v];
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

