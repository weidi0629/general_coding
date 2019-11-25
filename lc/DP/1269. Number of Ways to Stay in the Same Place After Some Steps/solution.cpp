/*
bottom up
The array size can be larger than the number of steps. We can ingore array elements greater than steps / 2, as we won't able to go 
back to the first element from there.

v[i]表示在位置i时，到回到0点的可以有几种
*/

int numWays(int steps, int arrLen) {
    int sz = min(steps / 2 + 1, arrLen);
    vector<int> v1(sz + 2), v2(sz + 2);
    v1[1] = 1;
    while (steps-- > 0) {
        for (auto i = 1; i <= sz; ++i)
            v2[i] = ((long)v1[i] + v1[i - 1] + v1[i + 1]) % 1000000007; // 上次计算后， 如果v[i-1]回到0点的次数是 5， 那么这次从v[i]我只要
            倒回到v[i-1]（消耗1step）。same as v[i+1], v[i](原地不动也算一步)
        swap(v1, v2);
    }
    return v1[1];
}

/*
top down 代码非常straightforward
We can use a simple DFS/recursion to form the solution.
The key observation is that we can prune all the positions where i>steps as we can never reach 0 in that case.
We can now use memoization to cache all our answers, the only thing we need to worry about is memory which can be solved by using the observation i>steps will return 0 which means i will never exceed steps/2 due to pruning.

每条小线路都会返回自己能不能达到要求，达到就把自己算作1 
*/
Solution

static int MOD=1e9+7;
class Solution {
public:
    vector<vector<int>> memo;
    int arrLen;
    int dp(int i, int steps)
    {
        if(steps==0&&i==0)                                             //Base condition
            return 1;
        if(i<0||i>=arrLen||steps==0||i>steps)					//Pruning.
            return 0;
        if(memo[i][steps]!=-1)         //If we have already cached the result for current `steps` and `index` get it.
            return memo[i][steps];
        return memo[i][steps]=((dp(i+1,steps-1)%MOD+dp(i-1,steps-1))%MOD+dp(i,steps-1))%MOD;        //Either move right, left or stay.
            
    }
    int numWays(int steps, int arrLen) 
    {
        memo.resize(steps/2+1,vector<int>(steps+1,-1));
        this->arrLen=arrLen;
        return dp(0,steps);
    }
};


