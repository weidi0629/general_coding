/*
https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76607/C%2B%2B-O(nlogn)-Time-O(n)-Space-MergeSort-Solution-with-Detail-Explanation

这题主要是 indices这个数组。因为答案要求的是需要在原本的index上记录结果，sort更应该说是sort他index， 例如

orit [12,15,3,1,6,10]
indice [3,2,5,4,0,1] 是记录的原始数组的index，如果把原始数组的值（按记录的index）放进去，就是排序过的



*/
