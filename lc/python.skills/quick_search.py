# prefix sum array
self.w = list(itertools.accumulate(w))

# binary search 
return bisect.bisect_left(self.w, a)

# get random number, range a to b
random.randint(a,b) 

# 1d, 2d dictionary 
self.times = defaultdict(lambda : defaultdict(lambda : [0, 0]))
self.transit = defaultdict(list)

# heap/priority queue with tuples 
heap = [(a,b,c)]
aa,bb,cc=heapq.heappop(heap)
heapq.heappush(heap,(i,j,k))

# 2-d dic
d = collections.defaultdict(dict)
for a, b, p in arr:
    d=[a][b] = p
# loop the 1st level, it would output the 2nd level key, NOT a dictionary
for i in d[x]:
  print(i) # 2nd level key
