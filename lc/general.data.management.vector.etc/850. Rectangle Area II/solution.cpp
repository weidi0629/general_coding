/*
1. get rid of the duplicated x, to make a clear x vector
2. hash the x, cause x may vary largely, but we only need to know x 是第几个
3. 分裂每一层，这个分裂已经在笔记里惊叹过了。sig == 1 表示这个y以上是有的，-1表示没有。每一层y也要排序，一层层扫
3. count[i]表示第i个x往后一个x的加减量。
4. 然后计算实际每个x值得距离，就要用x[i+1] - x[i]
5. 扫描时，记得第一层是0..
e.g. rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
*/


class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> x{0}; //初始是0
        for(auto r:rectangles){
            x.push_back(r[0]);
            x.push_back(r[2]);
        }
        std::sort(x.begin(),x.end());
        auto vector<int>::iterator uniq = std::unique(x.begin(),x.end());
        x = x.erase(uniq,x.end());
        unordered_map<int,int> x_i;
        for(int i=0;i<x.size();i++)  //step 2
            x_i[x[i]]=i;
        //进行分裂
        vector<int> count(x.size(), 0);
        vector<vector<int>> L;
        for(auto r:rectangles){
            int x0=r[0], y0=r[1], x1=r[2], y2=r[3];
            L.push_back{y0,x0,x1,1};  //这个地方原来没想出这么写,这个分裂是这题其中一个要点
            L.push_back{y1,x0,x1,-1};
        }
        std::sort(L.begin(),L.end());  // sort according to y
        int area=0,currenty=0,currentx=0;
        for(auto l:L){
            int y=l[0], x0 = l[1], x1 = l[2], sig = l[3];
            area += (y-currenty) * currentx;
            currenty =y;
            // 开始搞currentx了，先在这一把内给count计数，注意这一把内可能还有其他长方形的x,所以要for loop里面所有的
            for(int i=x_i[x0]; i< x_i[x1]; i++) // 取得 i
                count[i] += sig;
            currentx =0;
            for(int i=0;i<x.size();i++){  // 从这里开始要遍历所有的x，因为长方形多，每层都要加加减减做统计
                if(count[i]>0) //只要大于0，不需要知道是多少，需要算进去计算
                    currentx += x[i+1] - x[i];       
            }
        }
        return area;
    }
};
