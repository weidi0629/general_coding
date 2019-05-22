/*
因为要 O(n) time, 所以是左右夹当中，需要有个index mapping做如下mapping：
公式是  
(1 + 2*index) % (n | 1);
For an array with even length -
0 1 2 3 4 5
The mapping is the following -
0 -> 1 = 2 * 0 + 1
1 -> 3 = 2 * 1 + 1
2 -> 5 = 2 * 2 + 1
3 -> 0 = (2 * 3 + 1) % (size + 1)
4 -> 2 = (2 * 4 + 1) % (size + 1)
5 -> 4 = (2 * 5 + 1) % (size + 1)

For an array with odd length -
0 1 2 3 4 5 6
The mapping is the following -
0 -> 1 = 2 * 0 + 1
1 -> 3 = 2 * 1 + 1
2 -> 5 = 2 * 2 + 1
3 -> 0 = (2 * 3 + 1) % (size)
4 -> 2 = (2 * 4 + 1) % (size)
5 -> 4 = (2 * 5 + 1) % (size)
6 -> 6 = (2 * 6 + 1) % (size)

So for each i, its virtual index is 2 * i + 1. However, it must mod different numbers based on the parity of the length.
(n | 1) adds 1 to every even number to make it odd but does nothing when n is already an odd number.

*/

 public void wiggleSort(int[] nums) {
        int median = findKthLargest(nums, (nums.length + 1) / 2);
        int n = nums.length;

        int left = 0, i = 0, right = n - 1;

        while (i <= right) {

            if (nums[newIndex(i,n)] > median) {
                swap(nums, newIndex(left++,n), newIndex(i++,n));
            }
            else if (nums[newIndex(i,n)] < median) {
                swap(nums, newIndex(right--,n), newIndex(i,n));  // 注意这里不知道i换回来的是什么，所以要继续比较
            }
            else {
                i++;
            }
        }


    }

    private int newIndex(int index, int n) {
        return (1 + 2*index) % (n | 1);
    }
