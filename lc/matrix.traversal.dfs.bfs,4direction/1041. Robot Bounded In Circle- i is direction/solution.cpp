//idea: 只要最后的方向不是出事方向，肯定能回去

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0, y=0, i =0; // i is direnction 
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        for(auto ins : instructions){
            if(ins == 'R'){
                i = (i+1)%4;
            }else if (ins == 'L'){
                i = (i+3)%4;
            }else{
                x += dir[i][0];
                y += dir[i][1];
            }
        }
        return (x==0 && y==0) || i > 0;   
    }
};
