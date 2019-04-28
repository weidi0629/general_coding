- enumerator
  给list 一个index 

  a = [34,21,1,7]
  b= enumerate(sorted(a))
  b:
  0 1
  1 7
  2 21
  3 34
  
- lambda 
  - costs.sort(key = lambda x: x[0]-x[1])
  
- sort: 
  - list 直接sort 
    - costs.sort(key = lambda x: x[0]-x[1])
    - sorted(costs, key=lambda x: x[0] - x[1])
