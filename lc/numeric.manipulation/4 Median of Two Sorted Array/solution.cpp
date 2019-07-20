/*
https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation
主要是这个公式
left_part          |        right_part
A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
i 可以变换，但j的公式是不变的
j = (m + n + 1)/2 - i
*/

class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if (m > n) return findMedianSortedArrays(B, n, A, m);
    int minidx = 0, maxidx = m, i, j, num1, mid = (m + n + 1) >> 1,num2;
    while (minidx <= maxidx)
    {
      i = (minidx + maxidx) >> 1;
      j = mid - i;
      if (i<m && j>0 && B[j-1] > A[i]) minidx = i + 1;
      else if (i>0 && j<n && B[j] < A[i-1]) maxidx = i - 1;
      else
      {
        if (i == 0) num1 = B[j-1];  // 这个跟一下 j==0, i==m, j==n都表示某个特殊情况：left或者right part的某一部分是没有的，都跑到另个数组里去了。
        //比如这个情况就是，i==0， 比b[j]小的数一个没有，那么就说嘛A都在B的right part
        else if (j == 0) num1 = A[i - 1];
        else num1 = max(A[i-1],B[j-1]);
        break;
      }
    }
    if (((m + n) & 1)) return num1;
    if (i == m) num2 = B[j];
    else if (j == n) num2 = A[i];
    else num2 = min(A[i],B[j]);
    return (num1 + num2) / 2.;
  }
};
