/*
      1
      |
      v
      5
    ----
   |     | 
   |     |
   v     v
   2     3
  ^ |
  | |
  | v
   4

如果简单的按找parent的做法，有可能找到的是 5->2, 也有可能是 4->2， depends on 他们出现的顺序。所以不能简单的跟undirenct那样做。

算法是：如果找到了有两个parent的点（注意是最近的parent，不是总的root的parent），把有问题的两条都拿出来，然后去掉一条。做正常的union find，
如果还是找到有相同parent（注意这时是总得root的那种union find），那这个就把这条线弄出来。如果都valid，就是去掉的这条线有问题。
要问如何去掉一条边？就是把边的另一端设成0，在后面真的union find时不考虑0的情况

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
