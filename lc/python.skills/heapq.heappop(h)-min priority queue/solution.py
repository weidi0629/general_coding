 # 这题具体思路参照 DP folder里的分析 
 
 def assignBikes(self, workers, bikes):
        def dis(i, j):
            return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])
        h = [[0, 0, 0]] # 用法 
        seen = set()
        while True:
            cost, i, taken = heapq.heappop(h)  # 用法 
            if (i, taken) in seen: continue
            seen.add((i, taken))
            if i == len(workers):
                return cost
            for j in xrange(len(bikes)):
                if taken & (1 << j) == 0:
                    heapq.heappush(h, [cost + dis(i, j), i + 1, taken | (1 << j)])  # 用法 

                
# 632 Smallest Range Covering Elements from K Lists
'''
这题的算法思路跟cpp一样，只判断每个list第一位，以及所有遍历一来的最大值。主要这里要学习的还是headpq的用法。
'''
def smallestRange(self, A):
    pq = [(row[0], i, 0) for i, row in enumerate(A)]
    heapq.heapify(pq)
    
    ans = -1e9, 1e9
    right = max(row[0] for row in A)
    while pq:
        left, i, j = heapq.heappop(pq)
        if right - left < ans[1] - ans[0]:
            ans = left, right
        if j + 1 == len(A[i]):
            return ans
        v = A[i][j+1]
        right = max(right, v)
        heapq.heappush(pq, (v, i, j+1))
