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
        int[] dp = new int[n];//dp[i] means the maximum subarray ending with A[i];
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
当中可以删掉一个，那么最后结果要么就是当中一个都不删，要么就是删掉一个。如果当中删掉一个，就变成左边段跟又半段。上面的dp我们可以找到左半段的最大值。
那如何找到右半段呢，那就是反过来在找一次dp。最后比较每个每个点的左边跟右边的和，取最大的。当然还要跟之前的正反两次作比较
-----> i <-----
*/

class Solution 
{
public:
    int maximumSum(vector<int>& v) 
    {
        int res = 0, n = v.size();
        int cur_max = v[0], overall_max = v[0];
        vector<int> f(n);
        vector<int> b(n);
        f[0] = v[0];
        
        for(int i = 1; i < n; i++)
        {
            cur_max = max(v[i], cur_max + v[i]); 
            overall_max = max(overall_max, cur_max); 
  
            f[i] = cur_max; 
        }
        
        cur_max = overall_max = b[n - 1] = v[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            cur_max = max(v[i], cur_max + v[i]); 
            overall_max = max(overall_max, cur_max); 

            b[i] = cur_max; 
        }
        
        res = overall_max;
        for(int i = 1; i < n - 1; i++)
        {
            res = max(res, f[i - 1] + b[i + 1]);
        }
        return res;
    }
};

/*
设定两个参数。第一个就是按正常方法，一个都不删掉。第二个参数是之前已经删掉一个了。on the fly, 看哪个参数会最大
*/
   
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodel=0, del=0, res = arr[0];
        for(auto a:arr){
            if(a>=0){
                del+=a;
                nodel+=a;
            }else{
                del=max(nodel,del+a);//这是最关键的，del是之前删过一个参数，所以到这里已经是断点右边那段了。如果右边那段还比不删要短，还不如不删
                //不删也就是说把当前的值跳过，那del就是到上一个为止一直没删过的的最大值，也就是 nodel.注意这时nodel还没有赋值，所以是上一轮的值
                nodel+=a;                
            }
            
            // 下面两句可能会有点confusing，主要是为了最后一轮类似于 [-1,-1,-1,-1]这种准备的。如果上面一轮因为总和是负的被清零，那最后一个还是要取
            //要理解（重温算法）可以先跳过这两句
            if(del==0) del=INT_MIN;
            if(nodel==0) nodel=INT_MIN;
            
            res = max(res,max(del,nodel));
            //如果是小于0，那对后面也没有用处了，直接清零了。
            if(del<0) del=0; 
            if(nodel<0) nodel=0;
        }
        return res;
    }
};


// 最后更简洁的版本


int gmax = arr[0], max1 = arr[0]; 
int ignored = 0, notignored = 0;
for(int i=0; i<arr.size(); i++){

	ignored = max(notignored, ignored+arr[i]);
	notignored = max(arr[i], arr[i]+notignored);

	gmax = max({gmax, ignored, notignored});
	max1 = max(max1, arr[i]);
}
return max1<0?max1:gmax;  // if all elements are <0, return max element(max1 here) else subarray max(gmax here)  

