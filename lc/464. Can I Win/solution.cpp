/*
1. 这题key是多少和最后的d是多少是联系的
2. k是用二进制表示，0是没有用过，1是用过。因为题设只有20位，所以是够的。
3. 主要表达左右二进制的可能性(2^n)都跑过, mp用来记录提早结束

*/

class Solution {
public:
    bool canIWin(int m, int d) { // m==maxChoosableInteger; d==desiredTotal 
        int s = (1+m)*m/2;
        if(m>=d) return true; //just choose the max one
        if(m==d) return m%2==1; // whoever choose the last one
        if(s<d) return false; // impossible to win
        unordered_map<int,int> mp;// mp是用来记录early termianation 
        return dfs(m,0,d,mp);
    }
    
    bool dfs(int m, int k, int d, unordered_map<int,int>& mp){ //递归+循环+map遍历了所以2^n的可能性
        if(d<=0) return false; // impossible to win
        if(mp.count(k)) return mp[k]; // 这是很好的检查的mp有没有数据的方法
        for(int i=0; i<m; i++){
            if(!(k&&1<<i)&&!dfs(m,k|1<<i,d-i-1,mp)) return mp[k]=true; //1<<i表示第i位1，如果 m&1<<i是0，表示原来k的这位是0，还没有被搞过，
            //这次可以搞，于是dfs中‘k|1<<i’将这位赋1。在JAVA版本中，used[i]要归为（used[i] = false;），但这里的k是按值传递，所以自带了归位的效果。
        }
        return mp[k]=false;
    }
};

/* JAVA版本
https://leetcode.com/problems/can-i-win/discuss/95277/Java-solution-using-HashMap-with-detailed-explanation
/*
