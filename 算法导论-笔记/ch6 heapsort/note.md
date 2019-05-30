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









