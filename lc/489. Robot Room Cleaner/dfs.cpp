class Solution {
public:
    void dfs(Robot& robot,unordered_set<int>& visited, int x, int y, int dir ){
        int pos = (x<<16)+y; // serilize的方法
        if(visited.count(pos)) return; // 查询是否有过的方法
        robot.clean();
        static int nx[] = {-1,0,1,0};
        static int ny[] = {0,1,0,-1};
        visited.emplace(pos);
        for(int i=0; i<4; i++){ // 四个方向上，每个方向都要走，先确定次数，再看能不能走, move 跟这个loop的顺序要高清
            if(robot.move()){
                x = x + nx[dir];
                y = y + ny[dir];
                dfs(robot,visited,x,y,dir);
                robot.turnLeft();  //走过一次了，就要归位
                robot.turnLeft();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            dir = (dir+1)&3; //可以不用余数，这个方法很好
            robot.turnRight();
        }
    }
    
    void cleanRoom(Robot& robot) {
        unordered_set<int> visited;
        dfs(robot,visited,0,0,0);
    }
};
