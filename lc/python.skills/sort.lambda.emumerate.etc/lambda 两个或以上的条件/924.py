def minMalwareSpread(self, graph, initial):
        def find(x):
            if x != parents[x]:
                parents[x] = find(parents[x])
            return parents[x]
        def union(x, y):
            parents[find(x)] = find(y)
        # init
        n = len(graph)
        parents = range(n)
        # union
        for i in range(n):
            for j in range(i + 1, n):
                if graph[i][j] == 1:
                    union(i, j)
        area = collections.Counter(find(i) for i in range(n))
        malware = collections.Counter(find(i) for i in initial)
        return min(initial, key=lambda i: [(malware[find(i)] == 1) * -area[find(i)], i]) #要么前面的值最小，如果一样，就看哪个i小
'''        
The last line equals to :

        save, res = 0, min(initial)
        for i in initial:
            if malware[find(i)] == 1:
                if area[find(i)] > save:
                    save, res = area[find(i)], i
                elif area[find(i)] == save:
                    res = min(res, i)
        return res
        '''
