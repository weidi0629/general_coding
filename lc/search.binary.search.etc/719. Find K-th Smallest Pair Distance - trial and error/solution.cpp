/*
详细的解释在:
https://leetcode.com/problems/find-k-th-smallest-pair-distance/discuss/109082/Approach-the-problem-using-the-%22trial-and-error%22-algorithm
*/

public int smallestDistancePair(int[] nums, int k) {
    Arrays.sort(nums);
    
    int n = nums.length;
    int l = 0;
    int r = nums[n - 1] - nums[0];
    
    for (int cnt = 0; l < r; cnt = 0) {
        int m = l + (r - l) / 2; // 假设这是成立的
        
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && nums[j] <= nums[i] + m) j++; // 这种题目的关键，就是如何找这个与你找到中点的值比较的条件，这个条件必须简单。这里因为是排序过得，
            有后面一个可以代表前面一个的概念在
            cnt += j - i - 1;
        }
        
        if (cnt < k) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    return l;
}


