a>>b 
# read from left to right
# a move b position to right

2: 010, the 2nd position appear every 2 number: 2-010-yes, 3-011-yes,4-100-no,5-101-no,6-110-yes,7-111-yes,8-1000-no...
4: 100, the 3rd poistion appear every 4 number: 4-01000-yes, 5-0101-yes,6-0110-yes,7-0111-yes,8-1000-no...  
...


# how to get right-most digit 
a=a&(-a)
the way to get -a is, reverse every digit, then plus 1
12: 01100
~:  10100
  
# in binary count, how each bit change when add one (Single Number II)
all the left element must be 1 and itself should be zero
bit2 = bit2^(bit1&i)
bit3 = bit3^(bit2&bit1&i)

# how to reset binary counter:(Single Number II)
 it's the count of 1's, only all ones, then the mask become zero, the counter can & the mask to get reset
 mask = ~(y1 & y2 & ... & ym), where yj = xj if kj = 1, and yj = ~xj if kj = 0 (j = 1 to m)

# how to test if power of 2:
n&(n-1)==0 # 1 will gone, all the 0 right to that 1 will become 0

# how to test if power of 4:
(n-1)%3==0
#(1) 4^n - 1 = (2^n + 1) * (2^n - 1)
#(2) among any 3 consecutive numbers, there must be one that is a multiple of 3
#among (2^n-1), (2^n), (2^n+1), one of them must be a multiple of 3, and (2^n) cannot be the one, therefore either (2^n-1) or (2^n+1) must be a multiple of 3, 
#and 4^n-1 must be a multiple of 3 as well.
