'''
first is the basic method of the LIS
'''
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if len(nums)==0: return []
        dp = [[n] for n in nums]
        nums.sort()
        for i in range(len(nums)):
            for j in range(i):
                if nums[i]%nums[j]==0 and len(dp[j])+1 > len(dp[i]):
                    dp[i]=dp[j]+[nums[i]]             
        return max(dp, key=len)
    
 '''
 optimized version for the space complexity 
 dp is tuple (max size, the previous idx which can be divided without remainder)
 '''
        
     n = len(nums)
        if n <= 1:
            return nums
        nums.sort()
        dp = [(0, 0)] * n
        dp[0] = (1, 0)
        maxIndex, maxVal = 0, 1
        for i in range(1, n):
            dp[i] = max((dp[j][0] + 1, j) for j in range(i + 1) if nums[i] % nums[j] is 0)
            if dp[i][0] > maxVal:  # get the max size 
                maxIndex, maxVal = i, dp[i][0]
        i, lds = maxIndex, [nums[maxIndex]]
        while i != dp[i][1]: # only the starting element has no prevous divisor, idx == himself, like a linked list going back 
            i = dp[i][1]
            lds.append(nums[i])
        return lds
