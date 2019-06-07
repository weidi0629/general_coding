/*

比如最后的优化的结果是：

w1 --> B9

remaining state： 
w2 -> Bx 
w3 -> ...

remaining state 现在不知道，但如果假设我们知道的话，有一点是可以确定，这个state是优化的 - 值是最小的。为了保证优化，我们可以推断出dp公式：

dp[i][s] = min (dp[i][s], dp[i][prev] + distance[i][j])  j是遍历每一辆自行车，而prev是state，也是这题的另一个关键




*/
