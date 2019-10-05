/*
https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76607/C%2B%2B-O(nlogn)-Time-O(n)-Space-MergeSort-Solution-with-Detail-Explanation
这题跟493思路是一样的。但里面的搞法要更清楚一点

这里面有个隐藏的条件，两个数组排序的时候 
[1,3,4]
[2,4,6]
我们已经知道第二个数组所有的元素的位置要在第一个数组之后。所以在两个数组一个个排序时，如果第二个数组第一个值小于第一个数组第一个值，它拿出来排到
result同时，也要进行计数。下一个第一个数组的值如果排进来，要加上这个计数值。
注意如上面的例子，第一第二个数组已经排序过了，结果数组里的值已经赋值了。所以当第二个数组的数进结果数组时，不需要做什么事情 

*整个过程要点就是记录第二个数组进来时累计的semicount给第一个数组的值来用* 

另一个要点是：
这题主要是 indices这个数组。因为答案要求的是需要在原本的index上记录结果，sort更应该说是sort他index， 例如

orit [12,15,3,1,6,10]
indice [3,2,5,4,0,1] 是记录的原始数组的index，如果把原始数组的值（按记录的index）放进去，就是排序过的
很厉害。

这题还有用 bst, bit, segtree来解的，放在tree的板块里了
*/

class Solution {
protected:
    void merge_countSmaller(vector<int>& indices, int first, int last, 
                            vector<int>& results, vector<int>& nums) {
        int count = last - first;
        if (count > 1) {
            int step = count / 2;
            int mid = first + step;
            merge_countSmaller(indices, first, mid, results, nums);
            merge_countSmaller(indices, mid, last, results, nums);
            vector<int> tmp;
            //tmp.reserve(count); 
            int idx1 = first;
            int idx2 = mid;
            int semicount = 0;
            while ((idx1 < mid) || (idx2 < last)) {
                if ((idx2 == last) || ((idx1 < mid) &&
                       (nums[indices[idx1]] <= nums[indices[idx2]]))) {
		    tmp.push_back(indices[idx1]); // tmp 是 indices数组的tmp
                    results[indices[idx1]] += semicount; //两边数组都是排序过的，如果i 可以建立在i-1的结果上面
                    ++idx1;
                } else {
					          tmp.push_back(indices[idx2]);
                    ++semicount;
                    ++idx2;
                }
            }
            move(tmp.begin(), tmp.end(), indices.begin()+first); // 这题的排序是只排indice这个数组，不搞原来的
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n, 0);
        vector<int> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);
        merge_countSmaller(indices, 0, n, results, nums);
        return results;
    }
};
