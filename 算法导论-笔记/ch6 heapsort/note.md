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
4   largest =  l
5 else largest = i
6 if r <= A:heap-size and A[r] > = A[largest] 
7   largest  = r
8 if largest ¤ i
9   exchange A[i] with with A[largest]
10  MAX-HEAPIFY(A; largest)  

T(n) <= T(2n/3) + (1)  ~ lg(n)


6.3 Building a heap

-- A[(n/2+1) .. n ] are all leaves of the tree

BUILD-MAX-HEAP(A)
1 A:heap-size D A:length
2   for i = A.lenth/2 downto 1 //最底下一层，可以bottom up的做上面swap的交换，以此保证 maxheap的特性
3   MAX-HEAPIFY(A,i)


pending 6.4 heapsort algoithm 








