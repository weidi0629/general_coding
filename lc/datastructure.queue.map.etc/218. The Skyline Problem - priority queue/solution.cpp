/*
思考的思路：
1 要建立一个priority queue -> yes
2 主要比较的对象的是 h -> yes
3 右边也需要存下来，怎么弄 -> 也要插入到 queue
4 左边的点也要判断，怎么弄 -> 左边是靠一个个往前走的index来遍历
5 如果进来的左边的点小于queue里最高的右，那就是同一块的
6 pop时要一起带走与自己同一区块里，右边小于自己的点（这些个没有用，如果同绿色要带走蓝色）
大思想：y变动，就要存进结果
a. 要区分： 正在处理的那一坨里是不是新的进来，还是那坨之后的有新的进来
b. pop时，把比自己小的结束x全部pop掉，类似绿的跟蓝的
c. maxh变动了就要存进去 
https://www.youtube.com/watch?v=GSBLe8cKu0s
*/

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {  //  [ [2 9 10], [3 7 15], [5 12 12], first x, end x, high ]
        vector<pair<int, int>> res;
        int cur=0, cur_X, cur_H =-1,  len = buildings.size(); // cur is the index
        priority_queue< pair<int, int>> liveBlg; // first: height, second, end time
        while(cur<len || !liveBlg.empty())
        { 
            // if either some new building is not processed or live building queue is not empty
            cur_X = liveBlg.empty()? buildings[cur][0]:liveBlg.top().second;  // curx是每个building 左右两边的点变动 

            if(cur>=len || buildings[cur][0] > cur_X) // 因为上面第四点，如果大于的话，说明新的一块已经开始了，比如例图的粉色，那之前的不能等了，
                //一定要pop掉(上面思路6)类似绿的跟蓝的 
            {               
                while(!liveBlg.empty() && ( liveBlg.top().second <= cur_X) ) liveBlg.pop(); 
            }
            else
            { 
                cur_X = buildings[cur][0]; // 在同一区块里了，重新利用一下curx这个值，把所有同一起点的build都加进去
                while(cur<len && buildings[cur][0]== cur_X)  // go through all the new buildings that starts at the same point
                {  // just push them in the queue
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            cur_H = liveBlg.empty()?0:liveBlg.top().first; // outut the top one， 绿的进来时，最高的根本没有变，所以不予考虑
            if(res.empty() || (res.back().second != cur_H) ) res.push_back(make_pair(cur_X, cur_H));
        }
        return res;
    }
};



