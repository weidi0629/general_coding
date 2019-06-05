看这题原因是 215 kth largest number 

很像 full binary tree 

array A with two attributes:
  - A.length: number of elements in the array
  - A.heap-size how many elements in the heap are stored within array A 
  
calculate the left right:
PARENT (i)
  return bi=2c
LEFT(i)
  return 2i
RIGHT(i)
  return 2i + 1
  
-- Good implementations of heapsort often implement these procedures as “macros” or “inline” procedures. 因为操作很快，只是左移一位右移一位。

-- max-heap 
  - A[PARENT(i)] >= A[i]
  min-heap 正好相反

6.2 Maintaining the heap property

MAX-HEAPIFY.A; i /
1 l D LEFT.i /
2 r D RIGHT.i /
3   if l <=  A:heap-size and A[l] > A[i] //两个儿子里面取个最大的
4     largest =  l
5   else largest = i
6   if r <= A:heap-size and A[r] > = A[largest] 
7     largest  = r
8   if largest ¤ i
9     exchange A[i] with with A[largest]
10  MAX-HEAPIFY(A; largest)  

T(n) <= T(2n/3) + (1)  ~ lg(n)


6.3 Building a heap

-- A[(n/2+1) .. n ] are all leaves of the tree

BUILD-MAX-HEAP(A)
1 A:heap-size D A:length
2   for i = A.lenth/2 downto 1 //最底下一层，可以bottom up的做上面swap的交换，以此保证 maxheap的特性
3   MAX-HEAPIFY(A,i)


6.4 heapsort algoithm 

HEAPSORT(A)
1   BUILD-MAX-HEAP(A)
2   for i D A:length downto 2
3     exchange A[1] with A[i]
4     A:heap-size D A:heap-size - 1
5     MAX-HEAPIFY(A,1)

第一个总是最大的，把第一个跟最后一个互换，这样第一个数字就算sort结束了。那剩下的的tree肯定是破坏了原来有的heap tree结构，所以重新做一次
MAX-HEAP


6.5 priority queue using heap 

HEAP-EXTRACT-MAX(A)
1 if A:heap-size < 1
2   error “heap underflow”
3 max  = A[1]
4 A[1] = A[heap-size]
5 A:heap-size =  A:heap-size - 1 // 把第一个取掉，然后重新更新 
6 MAX-HEAPIFY(A,1)
7 return max

HEAP-INCREASE-KEY 其实就是update里面某个值 

HEAP-INCREASE-KEY(A, i, key)
1 if key < A[i]
2   error “new key is smaller than current key”
3 A[i] = key
4 while i > 1 and A[PARENT(I)] < A[i]  // 反复的更新他的parent， 确保所有的符合heap的要求
5   exchange A[i] with A[PARENT(i)]
6   i = PARENT(i)

增加一个， pseudo code 应该简单明了 
MAX-HEAP-INSERT.A; key/
1 A:heap-size = A:heap-size + 1
2 A[A:heap-size] = - 无穷
3 HEAP-INCREASE-KEY(A,A.heap-size,key)







