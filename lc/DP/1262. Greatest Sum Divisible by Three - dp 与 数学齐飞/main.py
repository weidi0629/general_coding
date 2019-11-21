'''
基本的是从二维开始，这题的思路其实没有下面lee的直观，记录只是为了记录想通的这个余数的公式 
dp[r][i] , r是余数 0,1,2。  i是遍历数组里的数 
在遍历余数 0,1,2时，我们有个target 余数 r， 比如 r = 1， 以及一个新的数 n = nums[i]，现在要找一个在0,1,2 里面的数 x，它跟n的和余3正好等于target 1
公式就是 x =  (r - n) % 3,
不行可以自己举个例子，
这题不太好的是，负数的余数搞不清楚，但知道这个应该可以理解得dp的公式： dp[r][i] = max(dp[x][i-1]+nums[i],dp[r][i-1])
'''
def maxSumDivThree(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0 for _ in range(n)] for _ in range(3)]
        dp[nums[0] % 3][0] = nums[0]
        for i in range(1, n):
            for r in range(3):
                include = dp[(r - nums[i]) % 3][i-1] + nums[i]
                if include % 3 == r:
                    dp[r][i] = max(dp[r][i-1], include)
                else:
                    dp[r][i] = dp[r][i-1]
        return dp[0][n-1]
        
        
        
        
        
'''
lee 的方法也是自己想到。关键是在每行更新时，有可能发生的情况会，同一轮里加上dp里面的数，可能余3之后结果是一样的，所以要使用最新的dp. 但又不能破坏原来的
dp里面的值。所以要做一个copy。 cpp是很明显的做了copy， 而python里， list[:]是做一个list 的 copy 
'''

#C++

    int maxSumDivThree(vector<int>& A) {
        vector<int> dp = {0, 0, 0}, dp2;
        for (int a : A) {
            dp2 = dp;
            for (int i: dp2) {
                dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);
            }
        }
        return dp[0];
    }
    
#Python:

    def maxSumDivThree(self, A):
        seen = [0, 0, 0]
        for a in A:
            for i in seen[:]:
                seen[(i + a) % 3] = max(seen[(i + a) % 3], i + a)
        return seen[0]
