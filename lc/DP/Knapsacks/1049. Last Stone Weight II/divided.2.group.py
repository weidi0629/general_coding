'''
分两组，两组的和相减就是最后的结果。
每个在A的元素过来，不是进 +的组就是进-的组
所有的结果都会枚举到，取最小的就是答案
'''
def lastStoneWeightII(self, A):
        dp, sumA = {0}, sum(A)
        for a in A:
            dp = {a + x for x in dp} | {a - x for x in dp}
        return min(abs(x) for x in dp)
