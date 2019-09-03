/*
注意这题找的不是遍历的每一个点，而是找个root点。 
题设要求的max，不是一般的优化问题，而是只针对去掉一个两个来说的。只要找到一个点开始遍历，最后都可以找到最优结果。
lee的解释网页
https://www.jianshu.com/p/30d2058db7f7
*/

// dfs 版本： 无论从哪个点着手，dfs都会给你遍历到所有的点。遍历到的点之后就不能用了
class Solution {
public:
    unordered_map<int,unordered_set<int>> rows, cols;
    int land;
    unordered_set<int> seenr, seenc;
    
    int removeStones(vector<vector<int>>& stones) {
        for(auto s:stones){
            rows[s[0]].insert(s[1]);
            cols[s[1]].insert(s[0]);
        }
        
        for(auto s:stones){
            int i = s[0], j = s[1];
            if(seenr.count(i)==0){ 
                land++;
                dfsr(i);
                dfsc(j);
            }
        }
        return stones.size() - land;
    }
    
    void dfsr(int i){
        if(seenr.count(i)==0){ 
            seenr.insert(i);
            for(auto j:rows[i]){
                if(seenc.count(j) ==0)
                    dfsc(j);
            }
        }
    }
    
    void dfsc(int j){
        if(seenc.count(j)==0){ 
            seenc.insert(j);
            for(auto i:cols[j]){
                if(seenr.count(i) ==0)
                    dfsr(i);
            }
        }
    }
};

/* union-find 版本
主要还是找根节点。随便哪个点找到的都可以做根节点，其他只要跟他连的（横竖）都要把它作为parent。无论横竖，只要有联系的，都最后爬到根节点（根据题意如果删除
的话，就是从最后一个开始删）。
*/
class Solution {
public:
    unordered_map<int,int> f;
    int land;
    
    int removeStones(vector<vector<int>>& stones) {
        for(auto s:stones){
            uni(s[0],~s[1]); // 这里取反是为了不让 row 跟 col冲突，把col转到另一个域里。
        }
        return stones.size()-land;
    }
    
    void uni(int i, int j){
        int x = find(i), y = find(j);
        if(x!=f[y]) f[y] =x, land--; // 因为要合并， 所以要减去1
    }
    
    int find(int x){
        if(f.count(x)==0) f[x] = x, land++; // 没见过的话，先给加1个默认你是个新东西，最后合并的话，会减去一个的
        if(f[x]!=x) f[x]=  find(f[x]);
        return f[x];
    }
};


