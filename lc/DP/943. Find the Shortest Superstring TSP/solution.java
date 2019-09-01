/*
本题第一步也是最难的一步就是转换问题为TSP： 把每个string看成一个点，点到点的成本就是需要在后面append几个字符。详见最后calc function。 这样的话，问题
就转化为把每个点(string)都跑一遍，然后返回最短成本的路线（每次点到点都要append一些东西，我们要找append最少的）。

问题转化后开始处理tsp，这题另一个难点是，最后要reconstruct 路径。 所以需要另一个辅助数组 path. 定义如下两个dp数组
dp[i][j] min cost achieve status i, with node j, 
path[i][j] the previous node before j
详细处理看代码注释

*/
class Solution {
    public String shortestSuperstring(String[] A) {
        int n = A.length;
        int[][] graph = new int[n][n];
        // build the graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = calc(A[i], A[j]);
                graph[j][i] = calc(A[j], A[i]);
            }
        }
        int[][] dp = new int[1 << n][n];
        int[][] path = new int[1 << n][n];
        int last = -1, min = Integer.MAX_VALUE;
		
        // start TSP DP
        for (int i = 1; i < (1 << n); i++) { // 这里的 i表示status， 用的是bit manipulation的技巧
            Arrays.fill(dp[i], Integer.MAX_VALUE);
            for (int j = 0; j < n; j++) { // j 表示第几个node，也就是往左边移多少位 
                if ((i & (1 << j)) > 0) { // 表示这个j比起上一个来说是新的，所以要开始寻找最小的的成本
                    int prev = i - (1 << j);  // 这是dp的常规做法，找之前的那个status
                    if (prev == 0) { // 这里表示 j is the only one, 状态也就是j一个，那从没有j，成本自然就是j的长度
                        dp[i][j] = A[j].length();
                    } else {
                        for (int k = 0; k < n; k++) {
                        // 小于 MAX_VALUE说明这条线路之前是来过的。
                            if (dp[prev][k] < Integer.MAX_VALUE && dp[prev][k] + graph[k][j] < dp[i][j]) {
                                dp[i][j] = dp[prev][k] + graph[k][j];
                                path[i][j] = k; //优化后，上一个来到j之前的node是k
                            }
                        }
                    }
                }
                if (i == (1 << n) - 1 && dp[i][j] < min) { //最后的点，这两个参数后面recontruct时要用的
                    min = dp[i][j]; 
                    last = j;
                }
            }
        }
		
        // build the path. 注意他要的是点的顺序，所以都是从path里面取出来
        StringBuilder sb = new StringBuilder();
        int cur = (1 << n) - 1;
        Stack<Integer> stack = new Stack<>();
        while (cur > 0) {
            stack.push(last);
            int temp = cur;
            cur -= (1 << last);
            last = path[temp][last]; // 在current status情况下，在达到last的点之前那个点是多少，这样来构建点的访问顺序
        }
		
        // build the result
        int i = stack.pop();
        sb.append(A[i]);
        while (!stack.isEmpty()) {
            int j = stack.pop();
            sb.append(A[j].substring(A[j].length() - graph[i][j])); //知道顺序后最后一步就是append一个长的string出来
            i = j;
        }
        return sb.toString();
    }
    /*
      如果 a跟b完全不搭界，那么a要到b的成本就是把b整个的都append在后面
    */
    private int calc(String a, String b) {
        for (int i = 1; i < a.length(); i++) {
            if (b.startsWith(a.substring(i))) {
                return b.length() - (a.length() - i); // a.lenth()-i是跟b不搭界的个数，公式整个的返回的就是b后面要append的个数
            }
        }
        return b.length();
    }
}
