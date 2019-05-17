/*
这题的常规做法是binary search。
这里的dp[i] 表示把数据从 i到L分成s组，能得到的‘最小的总和（也就是题目要得结果）’是多少
*/

public int splitArray(vector<int> nums, int m)
{
    int L = nums.size();
    vector<int> S(L+1);
    S[0]=0;
    for(int i=0; i<L; i++) // 取 prefix， 一半看到这种都要想到prefix
        S[i+1] = S[i]+nums[i];

    vector<int> dp(L);
    for(int i=0; i<L; i++) //这个求的是只分一组
        dp[i] = S[L]-S[i]; 

    for(int s=1; s<m; s++)
    {
        for(int i=0; i<L-s; i++) //最后剩余的不能小于s 不然分不了s组了。 i 从0开始，分一组是什么结果，从0开始，分两组是什么结果...
        {
            dp[i]=INT_MAX;
            for(int j=i+1; j<=L-s; j++)
            {//这个地方他已经降维到1维了。j是之前一轮的。比如之前是分了dp[j]表示分了1组，现在找到最优解给dp[i], dp[i]就是分两组的解了，这个值可以留到
            下一轮，分三组的时候用了
                int t = Math.max(dp[j], S[j]-S[i]); 
                if(t<=dp[i])
                    dp[i]=t;
                else
                    break;
            }
        }
    }

    return dp[0];
}
