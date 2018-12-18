def coinChange(self, coins, amount):
    coins.sort(reverse = True)
    lenc, self.res = len(coins), 2**31-1
    
    def dfs(pt, rem, count):
        if not rem:  #这里进去的话只有因为 rem == 0
            self.res = min(self.res, count) #越界了，定一下最小值
        for i in range(pt, lenc): #这里还是从pt开始应该理解没啥问题了。
            if coins[i] <= rem < coins[i] * (self.res-count): # if hope still exists
                dfs(i, rem-coins[i], count+1)

    for i in range(lenc):
        dfs(i, amount, 0) #每个i进去count都是从0开始，所以可以越早结束越好
    return self.res if self.res < 2**31-1 else -1
    
    '''
    if coins[i] <= rem < coins[i] * (self.res-count):这句最重要
    每次有比rem小的，rem都会减掉。但如果一直减掉后遇到的值没有比rem再小的，self.res永远不会被赋值。比如 coins = [2,5] amount = 11, 因为第三个5>1,
    而后面来的2也大于1.
    而如果有 coins[i] <= rem条件满足，为何有后面那半句呢？
    因为默认self.res是之前最小的，而count是目前已经用掉的，如果self.res-count就是你的余额，如果余额*目前的还不够，那肯定要增加个数，那么肯定比self.res
    还要大，那就不用搞了。
    
    
    '''
    
