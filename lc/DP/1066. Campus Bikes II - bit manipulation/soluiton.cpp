/*

比如最后的优化的结果是：

w1 --> B9

remaining state： 
w2 -> Bx 
w3 -> ...

remaining state 现在不知道，但如果假设我们知道的话，有一点是可以确定，这个state是优化的 - 值是最小的。为了保证优化，我们可以推断出dp公式：

dp[i][s] = min (dp[i][s], dp[i][prev] + distance[i][j])  j是遍历每一辆自行车，而prev是state，也是这题的另一个关键

## 这里另外一个很重要的是用bit来代表status 
在那个bit上是1， 就代表这个位置的自行车被用掉了， 比如 001100 表示第四第三辆自洗车被使用了。

*/

public int assignBikes(int[][] workers, int[][] bikes) {
        int n = workers.length;
        int m = bikes.length;
        int[][] dp = new int[n + 1][1 << m];
        for (int[] d : dp) {
            Arrays.fill(d, Integer.MAX_VALUE / 2);
        }
        dp[0][0] = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s < (1 << m); s++) {
                for (int j = 0; j < m; j++) {
                    if ((s & (1 << j)) == 0) { //只考虑目前状态跟目前状态‘之前’的状态。比如目前状态是 000111， 而自行车是 100000，不考虑。我们只保证
                      //000111的这个状态是最优的
                        continue;
                    }
                    int prev = s ^ (1 << j);
                    dp[i][s] = Math.min(dp[i - 1][prev] + dis(workers[i - 1], bikes[j]), dp[i][s]) ;// workers[i - 1] 表示dp[i][j]的i其实是
                  //一直到workder i-1 
                    if (i == n) {
                        min = Math.min(min, dp[i][s]);// 我们已保证之前那个状态是最优的，只要在最后一轮找最优值就行 
                    }
                }
            }
        }
        return min;
    }
  
    public int dis(int[] p1, int[] p2) {
        return Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
    }

// python的版本有点类似，但是因为用了 min priority queue, 就不需要自己判断了

def assignBikes(self, workers, bikes):
        def dis(i, j):
            return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])
        h = [[0, 0, 0]]
        seen = set()
        while True:
            cost, i, taken = heapq.heappop(h)
            if (i, taken) in seen: continue
            seen.add((i, taken))
            if i == len(workers): // 因为queue已经帮你最优过，取出来的肯定是最小的。注意这个i是有offset 1的
                return cost
            for j in xrange(len(bikes)):
                if taken & (1 << j) == 0: //如果本轮这个情况还没有计算过，那就计算一下 
                    heapq.heappush(h, [cost + dis(i, j), i + 1, taken | (1 << j)]) //这里每次扔进去的 i+1，是下一轮要计算的. 每一轮的i，都算下
                      // 不同的取自行车的情况
                      //跟上面的dp不同，这里的求最优值（min），queue给你自动算好了


