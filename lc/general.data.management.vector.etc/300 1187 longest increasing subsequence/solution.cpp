/*
首先先做300， lis。 
方法1是building tail in the fly 
(1) if x is larger than all tails, append it, increase the size by 1
(2) if tails[i-1] < x <= tails[i], update tails[i]

tail[i] 表示len = i 的数组，最小的tail
比如 [4,5] 
     [4,5,6]
现在来一个7， 他不会去更新len=2的数组，因为7比6还大，所以至少要更新len=3的数组

*/

public int lengthOfLIS(int[] nums) {
    int[] tails = new int[nums.length]; //
    int size = 0;
    for (int x : nums) {
        int i = 0, j = size;
        while (i != j) { // i,j都是index，本题中代表长度
            int m = (i + j) / 2;
            if (tails[m] < x)
                i = m + 1;
            else
                j = m;
        }
        tails[i] = x; // 其实binary search停在的是i-1的位置，所以是更新 i(i是长度)
        if (i == size) ++size;
    }
    return size;
}

/*
方法2是dp
dp[i]表示截止到i，最长的数组是多少, 应该是比较好理解的  
*/

public int lengthOfLIS(int[] nums) 
	{
		// Base case
		if(nums.length <= 1) 
			return nums.length;

		// This will be our array to track longest sequence length
		int dp[] = new int[nums.length];

		// Fill each position with value 1 in the array
		for(int i=0; i < nums.length; i++)
			dp[i] = 1;


		// Mark one pointer at i. For each i, start from j=0.
		for(int i=1; i < nums.length; i++)
		{
			for(int j=0; j < i; j++)
			{
				// It means next number contributes to increasing sequence.
				if(nums[j] < nums[i])
				{
					// But increase the value only if it results in a larger value of the sequence than T[i]
					// It is possible that T[i] already has larger value from some previous j'th iteration
					if(dp[j] + 1 > dp[i])
					{
						dp[i] = dp[j] + 1;
					}
				}
			}
		}

		// Find the maximum length from the array that we just generated 
		int longest = 0;
		for(int i=0; i < T.length; i++)
			longest = Math.max(longest, dp[i]);

		return longest;
	}



