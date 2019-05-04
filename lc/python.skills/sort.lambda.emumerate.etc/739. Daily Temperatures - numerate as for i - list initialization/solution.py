class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        res = [0]*len(T)
        stack = []
        for i,t in enumerate(T):
            while stack and t > T[stack[-1]]:
                j = stack.pop()
                res[j] = i - j
            stack.append(i)
        return res 
