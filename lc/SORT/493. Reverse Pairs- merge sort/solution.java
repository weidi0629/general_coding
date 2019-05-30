public int reversePairs(int[] nums) {
    return reversePairsSub(nums, 0, nums.length - 1);
}
    
private int reversePairsSub(int[] nums, int l, int r) {
    if (l >= r) return 0;
        
    int m = l + ((r - l) >> 1);
    int res = reversePairsSub(nums, l, m) + reversePairsSub(nums, m + 1, r);
        
    int i = l, j = m + 1, k = 0, p = m + 1;
    int[] merge = new int[r - l + 1];
        
    while (i <= m) {
        while (p <= r && nums[i] > 2 L * nums[p]) p++; //这里开始解决那个 c 
        res += p - (m + 1);// 里面都已经sort过了， 如果这个p可以，之前的都满足
				
        while (j <= r && nums[i] >= nums[j]) merge[k++] = nums[j++]; // merge sort从这里开始，注意while里面的j的保护
        merge[k++] = nums[i++];
    }
        
    while (j <= r) merge[k++] = nums[j++]; //漏网的， 这是merge sort的标准操作
        
    System.arraycopy(merge, 0, nums, l, merge.length);
        
    return res;
}
