/*
注意bit的update，是要先找到diff，再在所有经过的范围内加上这个diff 
*/

class NumArray(object):
    def __init__(self, nums):
        self.n = len(nums)
        self.a, self.c = nums, [0] * (self.n + 1) #要加一，因为root是dummy的
        map(self.update, range(self.n), nums) #后面跟两个参数

    def update(self, i, val):
        diff, self.a[i] = val - self.a[i], val #注意原始数组跟bit数组都要更新
        i += 1 #注意加1，root dummy
        while i <= self.n: #while 的使用
            self.c[i] += diff
            i += (i & -i)

    def sumRange(self, i, j):
        res, j = 0, j + 1 #注意加1，root dummy
        while j: 
            res += self.c[j]
            j -= (j & -j)
        while i:
            res -= self.c[i]
            i -= (i & -i)
        return res
