/*
这题最主要的是bit的方向是反的。
首先要回忆起bit，它是新建一个数组，通过2次方等性质，巧妙的把某些加在一起。可以参考下面链接里的两个图。
https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/

在这道题，我们要求的不是数组元素的和，而是数组个数的和，这点很重要。所以在insert时，我们只需要加 1， 而不是想一般的bit一样加上数组的值。

一般的bit，因为要求的是 0 到某个index的和，所以是 i-=i&(-i). 而这题，要求的是 i - nums.size(), 所以方向是反的。但是2次方巧妙的性质依然可以用，但是
是倒过来用的。非常厉害。下面应用一段评论：
Great solution with BIT!

Let me add more explanations for why the BIT approach is
"i += i&(-i)" for search, and
"i -= i &(-i)" for insert.
which is contrary to the "commonly" used way for BIT, where
"i += (-i)" for insert, and
"i -= i&(-i)" for search

First, the concept of "search(i)" here should be explained as "getSum(i)", which is to get the accumulative frequency from the starting index to i (inclusively), where i is an index in BIT.

In this problem, we want to get how many elements that are greater than 2 * nums[j], (num[j] is the current value that we are visiting). Therefore, instead of "searching down", here we need to "searching up".

Based on the classical BIT format, where:
"i += (-i)" for insert
"i -= i&(-i)" for search

One possible way is to use the getRange approach,
so we can use getSum(MaxNumberOfValue) - getSum(index(2*nums[j])) to get the number of elements that are greater than 2 * nums[j].

Another possible way is just like @fun4LeetCode implements,
we can reverse the direction for insert and search in BIT
so what we get is always the number greater than query values by using single search method.
*/

private int search(int[] bit, int i) {
    int sum = 0;
    
    while (i < bit.length) {
        sum += bit[i];
        i += i & -i;
    }

    return sum;
}

private void insert(int[] bit, int i) {
    while (i > 0) {
        bit[i] += 1;
        i -= i & -i;
    }
}

public int reversePairs(int[] nums) {
    int res = 0;
    int[] copy = Arrays.copyOf(nums, nums.length);
    int[] bit = new int[copy.length + 1];
    
    Arrays.sort(copy);
    
    for (int ele : nums) {
        res += search(bit, index(copy, 2L * ele + 1));
        insert(bit, index(copy, ele));
    }
    
    return res;
}

private int index(int[] arr, long val) {
    int l = 0, r = arr.length - 1, m = 0;
    	
    while (l <= r) {
    	m = l + ((r - l) >> 1);
    		
    	if (arr[m] >= val) {
    	    r = m - 1;
    	} else {
    	    l = m + 1;
    	}
    }
    
    return l + 1;
}
