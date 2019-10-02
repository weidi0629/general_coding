/*
思考的思路：
要建立一个priority queue -> yes
主要比较的对象的是 h -> yes
右边也需要存下来，怎么弄 -> 也要插入到 queue
左边的点也要判断，怎么弄 -> 左边是靠一个个往前走的index来遍历

如果进来的左边的点小于queue里最高的右，那就是同一块的
pop时要一起带走与自己同一区块里，右边小于自己的点（这些个没有用，如果同绿色要带走蓝色）

大思想：y变动，就要存进结果
1. 要区分： 正在处理的那一坨里是不是新的进来，还是那坨之后的有新的进来
2. pop时，把比自己小的结束x全部pop掉，类似绿的跟蓝的
3. maxh变动了就要存进去 
https://www.youtube.com/watch?v=GSBLe8cKu0s
*/
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {  //  [ [2 9 10], [3 7 15], [5 12 12], first x, end x, high ]
        int len = building.size(),curx, curh =-1,;
        priority_queue<pair<int,int>> bld; // {y, end x}
        int i // i: index
        for(auto b:buildings){
            // *** curx = bld.top().second; //end x of the highest y, 这里忘记check bld是不是empty 
            curx = bld.empty()? buildings[i][0]:bld.top().second;
            
            //if(curx>buidlings[i][0]){  // 在同一坨里有新的进来了  // ** 错误，需要>= 
            if(curx>=buidlings[i][0])   
                curx = buidlings[i][0];
                // *** 错误 ** 这个很重要，考虑corner case, 有相同的start, 都要insert 进去
                while(curx==buidlings[i][0])
                {
                    bld.insert(make_pair(buidlings[i][2],buidlings[i][1]));
                    i++;
                }
            }else if(i<=len){ //pop开始了，把x取出后pop掉，如果有比自己小的继续pop,//***错误，缺少cur的保护
                //curx = bld.top().second; ** 错误，这句不要的，跟外面那个句是重复的
                while(bld.top().second <= curx) bld.pop;
                
            }
            curh = bld.empty()?0:bld.top().first;
            if(res.back().second!=bld.top().first) res.insert(curx,curh);
        }
        return res;
    }
};
