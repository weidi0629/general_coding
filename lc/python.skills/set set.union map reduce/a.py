#632. Smallest Range Covering Elements from K Lists
'''
这个版本的算法跟cpp的大路算法有点不同。他先把所有的值打到一起，排序。然后通过这一个个值，在每个list里面寻找自己要的另外的值。
这里主要学习set, set.union, map reduce的用法。
而第二个lee的版本，是上面那个set版本的变通，更简单。但目的还是打到一起然后排序

'''
def smallestRange(self, A):
    A = [row[::-1] for row in A]
    
    ans = -1e9, 1e9
    for left in sorted(reduce(set.union, map(set, A))): # 二维数组的一个打成一个大的set方法
        right = -1e9
        for B in A:
            while B and B[-1] < left:
                B.pop()
            if not B:
                return ans
            right = max(right, B[-1])
        if right - left < ans[1] - ans[0]:
            ans = left, right
    return ans

## 版本2

def smallestRange(self, A):
        ans = -1e9, 1e9
        for right in sorted(set(x for l in A for x in l))[::-1]:
            for B in A:
                while B and right < B[-1]:
                    B.pop()
                if not B:
                    return ans
            left = min(B[-1] for B in A)
            if right - left <= ans[1] - ans[0]:
                ans = left, right
        return ans
