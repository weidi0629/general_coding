'''
还有一种思路：
Notice that this is equivalent to:
remove all the cells with value below which that there is still a path from beginning to the end.
The res is between the min value of the grid and value of min(begin,end). We use binary search here.
To check if the grid is still connected, use DFS.
'''

class Solution(object):
    def maximumMinimumPath(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        dire = [[0,1],[1,0],[-1,0],[0,-1]]
        def check(grid,tar):
            if grid[0][0] < tar:
                return False
            cur = (0,0)
            seen = set([(0,0)])
            def dfs(node):
                if node == (len(grid)-1,len(grid[0])-1):
                    return True
                for x,y in dire:
                    if 0<= x+node[0] < len(A) and 0<=y +node[1] < len(A[0]) and grid[node[0]+x][node[1]+y] >= tar and (node[0]+x,node[1]+y) not in seen:
                        seen.add((node[0]+x,node[1]+y))
                        if dfs((node[0]+x,node[1]+y)):
                            return True
                return False
            return dfs(cur)
			
        L = []
        for row in A:
            L += [i for i in row if i <= A[-1][-1]]
        L = set(L)
        L = sorted(L,reverse = True)
		
        low = 0 
        high = len(L)-1
        while low < high:
            idx = (low+high)//2
            if check(A,L[idx]):
                high = idx
            else:
                low = idx + 1
        return min(L[high],A[0][0])
