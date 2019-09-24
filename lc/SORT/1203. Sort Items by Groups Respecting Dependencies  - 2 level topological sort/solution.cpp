/*

第一步 先排序 group 
    每一个element 代表一个组，因为element是要连在一起的。所以element的顺序也带动组的顺序

第二步 再排序 组内
    如果两个element属于一个组，那就是组内有要排序的要求。
    
所谓排序，都要用 topologic sort 来排序, topologic sort就是算 in degree. 一边删一边push进结果数组

每个没有分配组的元素都自己成立一个新的组。等于一个组一个人，也就是下面grp的作用

*/


class Solution {
    // 首先要建立的一下 data structure
    map<int, set<int>> group2item; //组织架构，没有小组的项目会分配一个唯一的小组
    
    map<int, int> groupInNum;       //每个小组的入度
    map<int, set<int>> groupDir;   //小组的依赖图
    map<int, int> itemInNum;       //组内每个成员的入度
    map<int, set<int>> itemDir;    //组内的依赖图

    
public:
    // n # of elements, m # of group
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int minGroup = m;
        
        // 建立 grp -> ele 关系 
        for(int i=0;i<group.size();i++){
            if(group[i] == -1){
                group[i] = minGroup++;
            }
            group2item[group[i]].insert(i);
        }
        
        // 建立 组内 组外的关系图 
        // a,b in beforeItems[i] 需要出现在 i之前，所以是 a,b -> i 
        for(int to = 0; to < beforeItems.size(); to++){
            int toGroup = group[to];
            for(auto from: beforeItems[to]){
                // from:[a,b]
                int fromGroup = group[from];
                
                if(toGroup == fromGroup){ //处理组内问题 
                    itemDir[from].insert(to); // in degree 增加
                    itemInNum[to]++; //入度加一
                }else{ //处理组跟组的问题
                    if(groupDir[fromGroup].count(toGroup) == 0){ 
                        groupDir[fromGroup].insert(toGroup);// in degree 增加
                        groupInNum[toGroup]++; //入度加一
                    }
                }
            }
        }
        
        //第一步检查小组间是否有冲突
        queue<int> que;
        vector<int> groupAns;
        for(int to = 0; to < minGroup; to++){
            if(groupInNum[to] == 0){
                que.push(to);
                groupAns.push_back(to);
            }
        }
        
        while(!que.empty()){
            int from = que.front(); // grp which in degree is 0 
            que.pop();
            for(auto to: groupDir[from]){  // 它插入的点都要去掉
                groupInNum[to]--;
                if(groupInNum[to] == 0){
                    que.push(to);
                    groupAns.push_back(to);
                }
            }
        }
        if(groupAns.size() != minGroup){
            return {};
        }
        
        //第二部检查小组内的项目是否有冲突
        vector<int> ans;
               
        for(auto id: groupAns){ // 每一个排序过得组 
            auto& items = group2item[id];
            
            int num = 0;
            for(auto to: items){ // every ele in the grp 
                if(itemInNum[to] == 0){ // zero degree, just like group
                    que.push(to);
                    ans.push_back(to);
                    num++;
                }
            }
            
            while(!que.empty()){
                int from = que.front();
                que.pop();
                for(auto to: itemDir[from]){  // 它插入的点都要去掉
                    itemInNum[to]--;
                    if(itemInNum[to] == 0){
                        que.push(to);
                        ans.push_back(to);
                        num++;
                    }
                }
            }
            
            if(num != items.size()){
                return {};
            } 
        }
        return ans;
        
    }
};
