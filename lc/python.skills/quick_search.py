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

#
# sorted list - 
#
from sortedcontainers import SortedList
SList = SortedList()
# do the bisect
pos1 = bisect_left(SList, nums[i] - t)
# remove, one by one
# SList=[1,2,2,3]
# SList.remove(2) 
# SList=[1,2,3]
#https://leetcode.com/problems/contains-duplicate-iii/discuss/824603/Python-SortedList-O(n-log-k)-solution-explained.
