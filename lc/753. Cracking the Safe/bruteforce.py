class Solution:
    def crackSafe(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        ans="0"*n
        vis = set()
        for _ in range(k**n):  #一共有这么多种可能，现在只要找到一种新的东西，就去下一个
            #prev = ans[k-1:] # 这里错了
            prev = ans[-n+1:] if n>1 else '' #corner case 
            for i in range(k-1,-1,-1):
                if prev+str(i) not in vis: #找到一个新的了，直接break
                    vis.add(prev+str(i))
                    ans+=str(i)
                    break
        return ans
        
        
 #另外一个版本       
        
def crackSafe(self, n, k):
    s = '0' * (n - 1)
    D = '9876543210'[-k:] #把9876543210倒过来取k个，这句也是厉害
    for _ in range(k**n):
        s += next(d for d in D if (s + d)[-n:] not in s) #sub in s 是查substring
    return s
    
   '''
   next() return next iterator. 如果把next括号里的东西用list搞掉[d for d in D if (s + d)[-n:] not in s]，那它会自动搞成一个list
   但现在只有element d在输出，所以需要有个引擎把它搞起来。next就是干这活的。
   '''
        
