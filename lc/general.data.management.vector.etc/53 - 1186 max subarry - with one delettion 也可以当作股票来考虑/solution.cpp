/*
53是1186的基础
单纯的53题只要知道最大值是多少，那我们只要维护一个参数就行
*/
public static int maxSubArray(int[] A) {
    int maxSoFar=A[0], maxEndingHere=A[0];
    for (int i=1;i<A.length;++i){
    	maxEndingHere= Math.max(maxEndingHere+A[i],A[i]); //关键的这句，意思是如果我加上之前那坨还没有我自己的大，那不如从我自己开始
    	maxSoFar=Math.max(maxSoFar, maxEndingHere);	
    }
    return maxSoFar;
}

/*
但1186需要维护每个点的最大值的信息，所以53题用一个dp的数组解法来解，为了给1186做准备，但想法是一样的
*/

public int maxSubArray(int[] A) {
        int n = A.length;
        int[] dp = new int[n];//dp[i] means the maximum subarray ending with A[i];就是取不取A[i]不一定，但是这个结果是到A[i]为止的最大值
        dp[0] = A[0];
        int max = dp[0];
        
        for(int i = 1; i < n; i++){
            dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);//这之前要是小于0，肯定就拖累我了，那我就不要了。跟上面那个方法意思一样。
            max = Math.max(max, dp[i]);
        }
 
        return max;
}

/*
现在开始接1186。 题设是：Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one 
element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at 
least one element left and the sum of the remaining elements is maximum possible.
也就是说运行你删掉一个。
*/

/*
第一种解法是： 
*/




