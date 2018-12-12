/*
不能简单的考虑duplicated parents, 比 [[4,2],[1,5],[5,2],[5,3],[2,4]]got [5,2] but [4,2] expected，
and [[2,1],[3,1],[4,2],[1,4]] got [3,1] but [2,1] expected。
有个图在狗哥.doc里可以看看
*/

class Solution {  // find the duplicated parents or circle
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> p(edges.size()+1,0),cana,canb;
        for(auto e:edges){
            if(p[e[1]]==0)
                p[e[1]] = e[0];
            else{
                //canb = {e[0],e[1]};//这里错了，e[0]已经变掉了
                canb = {p[e[1]],e[1]};//这是答案
                cana = e;
                e[1] = 0; // will skip this later
            }
        }
        
        //finding circle 
        for(int i=0;i<p.size();i++) p[i] = i;
        for(auto e:edges){
            if(e[1] == 0) continue; 
            int u = find(p,e[0]), v=find(p,e[1]);  //这个跟答案有所不同，答案的v没有求parent,原因是现在已经没有duplicated parents了， 但是我觉得就算求了问题也不大
            if(u==v){
                if (cana)
                    return cana;
                else return e
            }
            p[v] = u;
        }
        return canb;
    }
    
    int find(vector<int>& p, int v){ // union find pattern
        if(v!=p[v])
            p[v] = find(p[v]);
        return p[v];
    }
};
