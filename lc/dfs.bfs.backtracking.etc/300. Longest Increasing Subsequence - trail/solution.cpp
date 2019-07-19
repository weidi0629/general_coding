/*

注意这题是可以用dp解的。
LC 上的解释：
tails is an array storing the smallest tail of all increasing subsequences with length i+1 in tails[i].
For example, say we have nums = [4,5,6,3], then all the available increasing subsequences are:

len = 1   :      [4], [5], [6], [3]   => tails[0] = 3
len = 2   :      [4, 5], [5, 6]       => tails[1] = 5
len = 3   :      [4, 5, 6]            => tails[2] = 6
We can easily prove that tails is a increasing array. Therefore it is possible to do a binary search in tails array to find the one needs update.

Each time we only do one of the two:

(1) if x is larger than all tails, append it, increase the size by 1
(2) if tails[i-1] < x <= tails[i], update tails[i]

注意看下面代码解释
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> trail(n);
        int size=0;
        for(auto x:nums){
            int i=0, j=size;
            int m = (i+j)/2;
            while(i != j){
                if(x>trail[m])
                    i = m+1;
                else
                    j=m;
            }
            trail[i] = x; // i-1 长度的最小尾(min-max概念)， 注意随着n的往前，每次size都会check一次
            if(i==size) size++; //找到最终的长度，但是这个长度会在后面n往前的时候更新。 比如 [10,9,2,5,3,7,101,18]， 在3时并没有更新到size=4，size还是2，没有关系，后面到7还是size=2来搞，看看能不能搞到3   
        }
        return size; 
    }
};
