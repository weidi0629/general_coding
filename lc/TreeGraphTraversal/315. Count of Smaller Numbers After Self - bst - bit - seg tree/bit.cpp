/*
首先要知道bit的功能是什么： 返回到index = i 之前，所有元素的和。

这题非常巧妙的变化了 index跟value的概念。如现在 num[i] = 27. 我们要知道从 i ~ end, 小于27的元素有几个。那可以这样想一个数组：
A = [],每个元素代表它这个index的值有几个  比如 [0, 1, 3, 4 .. ] 代表 元素0有0个，1有1个，2有3个，3有4个。那也就是说，小于27的元素，用bit的方法求和
就可以了。
也就是说，原来27的是value，转换成bit的数组，就是index了，那27来了一个，在bit[27]上记一笔 ++就可以。但因为bit的兴致，光index = 27记一笔还不行，要
i+=i(-i)

还有两个要点，用这个方法，一定要从后往前，那每次来的点，直接求和就行，以为目前写进bit数组的，都是它之前（之后）的数。
另外，因为index不能是负的，所以要做个min max的提升，并且bit的大小是max min之间的距离（太大的话，就不适合这个方法了，浪费内存）

*/

public class Solution {
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> res = new LinkedList<Integer>();
        if (nums == null || nums.length == 0) {
            return res;
        }
        // find min value and minus min by each elements, plus 1 to avoid 0 element
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            min = (nums[i] < min) ? nums[i]:min;
        }
        int[] nums2 = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            nums2[i] = nums[i] - min + 1;
            max = Math.max(nums2[i],max);
        }
        int[] tree = new int[max+1];
        for (int i = nums2.length-1; i >= 0; i--) {
            res.add(0,get(nums2[i]-1,tree));
            update(nums2[i],tree);
        }
        return res;
    }
    private int get(int i, int[] tree) {
        int num = 0;
        while (i > 0) {
            num +=tree[i];
            i -= i&(-i);
        }
        return num;
    }
    private void update(int i, int[] tree) {
        while (i < tree.length) {
            tree[i] ++;
            i += i & (-i);
        }
    }
}
