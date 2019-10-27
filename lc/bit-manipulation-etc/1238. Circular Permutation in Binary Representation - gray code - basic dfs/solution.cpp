/*
这题有两种解法，一个是gray code， 一个是基本解法。最起码基本解法需要会做（写在后面） 

gray code:
https://cp-algorithms.com/algebra/gray-code.html
这个帖子里还有反gray code的求法

For example, the sequence of Gray codes for 3-bit numbers is: 000, 001, 011, 010, 110, 111, 101, 100, so G(4)=6.

int g (int n) {
    return n ^ (n >> 1);
}
所以 n就是他的index，而 return的就是他的gray code
一个简单的证明：
n是index， G(n)是它返回的值
Let's look at the bits of number n and the bits of number G(n). Notice that i-th bit of G(n) equals 1 only when i-th bit of n equals 
1 and i+1-th bit equals 0 or the other way around (i-th bit equals 0 and i+1-th bit equals 1). 
Thus, G(n)=n⊕(n>>1): 以为以上这个特性，往右移一格做异或，就可以把G(n)的1 炸出来
e.g.
G(n): 000, 001, 011, 010, 110, 111, 101, 100
n:    000, 001, 010, 011, 100, 101, 110, 111 

最后回到这题的题设，他不是要从0开始，而是要从某个数（start）开始。最简单的办法，就是把 G(n) 每个数都跟start做个异或。 就从start开始并且circular了

*/

vector<int> res;
        for (int i = 0; i < 1 << n; ++i)
            res.push_back(start ^ i ^ i >> 1);
        return res;
        
python:
 def circularPermutation(self, n, start):
     return [ start ^ i ^ i>>1 for i in range(1<<n)]


// 基本解法： 自己做的时候思路基本正确，但是dfs到底返回什么有所纠结，看程序前可以想一下，返回什么？ 

/*
https://leetcode.com/problems/circular-permutation-in-binary-representation/discuss/414145/Java-DFS-%2B-Bit
帖子上面写的更基本，
下面回复里有个版本更清楚，贴在下面。这个版本紧靠gray code变化的规律。 都是从最0位开始flip，如果见过，就把高位变1，继续从0位开始flip
G(n): 000, 001, 011, 010, 110, 111, 101, 100

但是基本那个版本，没有gray code概念也是可以做
*/

class Solution {
    List<Integer> list;
    
    public List<Integer> circularPermutation(int n, int start) {
        list = new LinkedList<>();
        boolean[] visited = new boolean[1<<n];
        dfs(n, start, visited);
        return list;
    }
  
    private void dfs(int n, int start, boolean[] visited) {
        if (visited[start]) {
            return;
        }
        list.add(start);
        visited[start] = true;
        for (int i = 0; i<n; i++) {
            // flip ith bit
            int bit = 1 << i;
            int neighbor = start ^ bit;
            dfs(n, neighbor, visited);
        }
    }
}

