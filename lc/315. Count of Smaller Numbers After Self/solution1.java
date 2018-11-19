class Solution {
    int[] count;
    int[] helper;
    int[] nums;
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        this.nums = nums;
        count = new int[n];
        helper = new int[n];
        int[] index = new int[n];
        for (int i = 0; i < n; i++) {
            index[i] = i;
        }
        
        mergeSort(index, 0, n - 1);
        List<Integer> res = new ArrayList();
        for (int i = 0; i < n; i++) {
            res.add(count[i]);
        }
        
        return res;
    }
    
    private void mergeSort(int[] index, int start, int end) {
        if (start >= end) return;
        
        int mid = (start + end) / 2;
        
        mergeSort(index, start, mid);
        mergeSort(index, mid + 1, end);
        
        merge(index, start, mid, end);
        return;
    }
    
    private void merge(int[] index, int start, int mid, int end) {
        int rightCount = 0;
        int i = start, j = mid + 1, k = start;

        for (int a = start; a <= end; a++) {
            helper[a] = index[a];
        }
        
        while (i <= mid || j <= end) {
            if (i > mid || j <= end && nums[helper[i]] > nums[helper[j]]) {
                rightCount++;
                index[k++] = helper[j++];
            } else {
                count[helper[i]] += rightCount;
                index[k++] = helper[i++];
                
            }
        }
        
        return;
    }
    
}
