/*
如果经过若干列的替换，某一行都是一样的数，而另外一行也都变成一样的，那这两行的关系肯定是只有两种，要么都是一样，要么截然相反（这点应该比较好理解）。

有一个好办法把这两种情况都转换成一样的数字： xor -- 把所有的数字都跟第一个数字做xor。 因为这两行是截然相反的，那第一个数肯定也是反的，后面所有跟他们做
xor的结果应该是一样。

101 -> 010
010 -> 010 

所以python一行就可以搞定了
 return max(collections.Counter(tuple(x ^ r[0] for x in r) for r in A).values())
 
 下面是硬做的办法，但是思路更清楚： 查找一样活着完全相反的
*/

class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int ans = 0;
        int m = matrix.length, n = matrix[0].length;
        int[] flip = new int[n]; // 相反的数组 
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) flip[j] = 1 - matrix[i][j];
            for(int k = 0; k < m; k++) {
                if(Arrays.equals(matrix[k], matrix[i]) || Arrays.equals(matrix[k], flip)) cnt++; // c++ 里直接相等就行
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
