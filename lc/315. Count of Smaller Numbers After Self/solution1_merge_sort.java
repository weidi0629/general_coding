/*
MergeSort-based solution is a standard way to solve problems related to inverse numbers.

Here is an example to illustrate the general idea of MergeSort-based algorithm:

Now we want to consider an array

            6 4 1 8 7 5 2 9
First thing first, split the array into to subarrays:

            6 4 1 8
            7 5 2 9
and then calculate the inverse numbers within the group:

                  1 4(1) 6(1,4) 8
                  2 5(2) 7(2,5) 9
where the numbers in the parentheses are the numbers that should be counted when we calculate the inverse number.
Now we need to merge these two arrays into one sorted array. The first element to be put into the sorted destination array is the "1" in the first array.

 1                  4(1) 6(1,4) 8
                  2 5(2) 7(2,5) 9               merged elements in the 2nd array = ()
The second element to merge is the "2" in the second array:

 1 2                4(1) 6(1,4) 8
                    5(2) 7(2,5) 9               merged elements in the 2nd array = (2)
The third element to merge is the "4" in the first array:

 1 2 4(1,2)              6(1,4) 8
                    5(2) 7(2,5) 9               merged elements in the 2nd array = (2)
When we merge the "4(1)", we found that "4" is actually greater than all merged elements in the second array (i.e. [2]). Therefore, we also need to consider those elements. Therefore, the numbers in the parenthese of 2 become (1)+(2) = (1,2). Next step:

 1 2 4(1,2) 5(2)         6(1,4) 8
                         7(2,5) 9               merged elements in the 2nd array = (2,5)
Next (add the inverse number of element "6" by 2)

 1 2 4(1,2) 5(2) 6(1,4,2,5)     8
                         7(2,5) 9               merged elements in the 2nd array = (2,5)
So and so forth, finally reach

 1 2 4(1,2) 5(2) 6(1,4,2,5) 7(2,5) 8(2,5,7) 9
                                                merged elements in the 2nd array = (2,5,7,9)
Additionally, when we need to count the inverse number, we do not need to record the exact elements, we only need to record the numbers. So, we can use a variable to record the number of "merged elements in the 2nd array" (for example, semilen in the code beneath) and the number of smaller elements of each element (for example, results[idx] in the code beneath).

Complexities:

Time: O(n log n)

Space: O(n)

*/
class Solution {
    int[] count;
    int[] helper;
    int[] nums;
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        this.nums = nums;
        count = new int[n];
        helper = new int[n];
        int[] index = new int[n];//
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
        int i = start, j = mid + 1, k = start; // k 是用来更新index数组的

        for (int a = start; a <= end; a++) {
            helper[a] = index[a]; //这时index就没有用了，等待之后的更新
        }
        
        while (i <= mid || j <= end) {
            if (i > mid || j <= end && nums[helper[i]] > nums[helper[j]]) { //前面这个 i > mid 的作用是，如果i(前半段已经搞完了)， 
                rightCount++; // 这个是把右边半部分小于左半部分的数记下来。注意这个参数是累加的，考虑如果左边第一个数比右边都大，左边第二个数肯定也
                              //比右边所有的数都大。
                index[k++] = helper[j++]; //更新index， 谁小去前面 
            } else {
                count[helper[i]] += rightCount;//这里特别注意，count的参数是helper[i]. helper跟index都是存的原数组的index，因为原数组的顺序
                //是不能动的
                index[k++] = helper[i++];
                
            }
        }
        
        return;
    }
    
}
