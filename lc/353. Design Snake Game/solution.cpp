class SnakeGame {
public:
    
    set<pair<int,int>> hist; // history
    deque<pair<int,int>> q; // all info for the snake
    int w=0, h=0, pos=0;
    vector<pair<int, int>> f;
        
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        q.push_back({0,0});
        w = width;
        h = height;
        f=food;
    }
    
    
    int move(string direction) {
        int row = q.back().first, col = q.back().second; // 把头的坐标线搞出来
        pair<int,int> tail = q.front(); // 把尾巴搞出来 
        q.pop_front();
        hist.erase(tail);
        
        //上下移动
        if(direction == "up")
            row++;
        if(direction == "down")
            row--;
        if(direction == "left")
            col--;
        if(direction == "right")
            col++;
        // 越界，碰到自己没？
        if(row<0||row>h||col<0||col>w||hist.count(make_pair(row,col)))
            return -1;
        q.push_back(make_pair(row,col)); //新的头
        hist.insert(make_pair(row,col)); //新的头
        if(pos>=f.size())
            return q.size()-1;
            
        //吃到了
        if(row==f[pos].first||col == f[pos].second){
            pos++;
            hist.insert(tail); // 尾巴也得加进去
            q.push_front(tail); //尾巴重新回去，因为吃了一个东西
        }
        return q.size()-1;
         
    }
};

 
