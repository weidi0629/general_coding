[0,1,1]
[1,0,0]
[1,1,1]

zip(*A)  =>

(0, 1, 1)
(1, 0, 1)
(1, 0, 1)


首先 * 作用是告诉function传入的参数将是一个连续的obj，比如list，arr之类

zip基本作用是将两个传进去的list的，两两联合起来，比如 
zip([1,2,3],[4,5,6]) => [1,4][2,5][3,6]

那当zip一个矩阵（list[list]）时,就是每一行的同一个位置的数结合起来 
[0,1,1]
 | | |
 v v v
[1,0,0]
 | | |
 v v v 
[1,1,1]

=>

(0, 1, 1)
(1, 0, 1)
(1, 0, 1)

 def countServers(self, A):
        X, Y = map(sum, A), map(sum, zip(*A))
        return sum(X[i] + Y[j] > 2 for i in xrange(len(A)) for j in xrange(len(A[0])) if A[i][j])
