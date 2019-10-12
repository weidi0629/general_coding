/*

紧抓median的概念，median的左边右边的element的个数是一定要一样的。 那如果按题意是两个数组怎么办 

 ----- i ------    长度m ， 已知
  ---- j ----   长度n ， 已知
  
  比如这两个数组，一个分到了i ，一个分到了 j， 如果median就产生在他们两个之中。首先，也是最难得，是取得i跟j的关系： 根据长度 
  i+j = m-i + n - j  => j = (m+n)/2 - i 
  这里有个隐藏的条件 m>n (估计面试时不会想得到)， 因为 i ~ (0,m), 如果 i = m, 那 j = n/2 - m/2, j不能是负的，所以n要大于m
  
  所以题目变成只要找i就可以了，用binary search， 范围是 0-m ， 每次 i 就是 mid
  
  判断段条件就是  i-1, i, j-1, j （这个应该清楚）
  edge case 也不难， 比如 i == 0， 说明整个数组都去了下面数组的右边 
  
  如果m+n是偶数的话 
  
  左边的（i-1, j-1） 取大的这个，右边取小的那个： 这点应该也比较好理解 

https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation
*/

def median(A, B):
    m, n = len(A), len(B)
    if m > n:
        A, B, m, n = B, A, n, m
    if n == 0:
        raise ValueError

    imin, imax, half_len = 0, m, (m + n + 1) / 2
    while imin <= imax:
        i = (imin + imax) / 2
        j = half_len - i
        if i < m and B[j-1] > A[i]:
            # i is too small, must increase it
            imin = i + 1
        elif i > 0 and A[i-1] > B[j]:
            # i is too big, must decrease it
            imax = i - 1
        else:
            # i is perfect

            if i == 0: max_of_left = B[j-1]
            elif j == 0: max_of_left = A[i-1]
            else: max_of_left = max(A[i-1], B[j-1])

            if (m + n) % 2 == 1:
                return max_of_left

            if i == m: min_of_right = B[j]
            elif j == n: min_of_right = A[i]
            else: min_of_right = min(A[i], B[j])

            return (max_of_left + min_of_right) / 2.0
