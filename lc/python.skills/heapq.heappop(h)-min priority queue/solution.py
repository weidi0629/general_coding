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
