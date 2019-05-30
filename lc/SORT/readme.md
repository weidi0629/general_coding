这个帖子说的这个 总结非常好，要先寻找到这个c， 然后看解决的办法
Many problems involving arrays can be solved by breaking down the problem into subproblems applied on subarrays and then link the 
solution to the original problem with those of the subproblems, to which we have sequential recurrence relation and partition 
recurrence relation. For either case, it's crucial to identify the subproblem C and find efficient algorithm for approaching it.

If the subproblem C involves searching on "dynamic searching space", try to consider data structures that support relatively fast 
operations on both searching and updating (such as self-balanced BST, BIT, Segment tree, ...).

If the subproblem C of partition recurrence relation involves sorting, Merge-sort would be a nice sorting algorithm to use. 
Also, the code could be made more elegant if the solution to the subproblem can be embedded into the merging process.

If there are overlapping among the subproblems T(i, j), it's preferable to cache the intermediate results for future lookup.

Lastly let me name a few leetcode problems that fall into the patterns described above and thus can be solved with similar ideas.
