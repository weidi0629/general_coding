/*

正规的topological sort可能会有多个结果，主要的算法是： 
we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. Finally, print contents of stack

详细的程序可以看， 画个图还是比较好理解。
https://www.geeksforgeeks.org/topological-sorting/

--- 但这道题目其实并没有考怎么求topological的定义，而是紧抓下面这个定理
If a topological sort has the property that all pairs of consecutive vertices in the sorted order are connected by edges, then these edges form a directed Hamiltonian path in the DAG.
感觉这是一个冲要条件。
https://en.wikipedia.org/wiki/Topological_sorting#Uniqueness

题设给的org其实已经是一个topological sort的结果，让验证的是他的正确性跟独一性
下面两个方法一个正过来验证，一个是反过来验证。

*/

//正过来
 bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.empty()) return false;
        vector<int> pos(org.size()+1);
        for(int i=0;i<org.size();++i) pos[org[i]] = i;
        
        vector<char> flags(org.size()+1,0);
        int toMatch = org.size()-1;
        for(const auto& v : seqs) {
            for(int i=0;i<v.size();++i) {
                if(v[i] <=0 || v[i] >org.size())return false;
                if(i==0)continue;
                int x = v[i-1], y = v[i];
                if(pos[x] >= pos[y]) return false;// 验证topological 正确性
                if(flags[x] == 0 && pos[x]+1 == pos[y]) flags[x] = 1, --toMatch; // flag 表示 x已经处理过了。 
            }
        }
        return toMatch == 0;
    }
    
    
    //正过来
bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.size() == 0) return false;
        int n = org.size(), count = 0;
        unordered_map<int, unordered_set<int>> graph;   // record parents
        vector<int> degree(n+1, 0); // record out degree
        for (auto s : seqs) {   // build graph
            for (int i = s.size()-1; i >= 0; --i) {
                if (s[i] > n or s[i] < 0) return false; // in case number in seqs is out of range 1-n
                if (i > 0 and !graph[s[i]].count(s[i-1])) {
                    graph[s[i]].insert(s[i-1]);
                    if (degree[s[i-1]]++ == 0) count ++;
                }
            }
        }
        if (count != n-1) return false; // all nodes should have degree larger than 0 except the last one
        for (int i = n-1; i >= 0; --i) {    // topological sort
            if (degree[org[i]] > 0) return false;   // the last node should have 0 degree
            for (auto p : graph[org[i]]) 
                if (--degree[p] == 0 and p != org[i-1]) //紧抓定义：如果是0表示是给的topologic sort中i之前的结束的点。p是graph里来的，说明肯定
                有edge连着。所以在org里面应该是连着的
                    return false;
        }
        return true;
    }
