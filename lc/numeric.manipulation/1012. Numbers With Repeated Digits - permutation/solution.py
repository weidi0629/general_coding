https://leetcode.com/problems/numbers-with-repeated-digits/discuss/256866/Python-O(logN)-solution-with-clear-explanation


# given number n, see whether n has repeated number
def has_repeated(n):
    str_n = str(n)
    return len(set(str_n)) != len(str_n)

def permutation(n, k):
    prod = 1
    for i in range(k):
        prod *= (n-i)
    return prod

# calculate number of non-repeated n-digit numbers
# note: the n-digit number can't start with 0
# i.e: n_digit_no_repeat(2) calculates the non-repeated
#   numbers in range [10, 99] (inclusive)
def n_digit_no_repeat(n):
    if n == 1:
        return 9
    else:
        return  9 * permutation(9, n-1)

class Solution(object):
    def numDupDigitsAtMostN(self, N):
        """
        :type N: int
        :rtype: int
        """        
        N_str = str(N)
        n_digit = len(N_str)
        digits = map(int, N_str) # map 回的是个list
        result = N - 1
        prefix = 0
        # 把 target 位数之前的都处理掉，比如 12345， 处理掉 10000 之前的
        # 1 位数就是 9个， 2位数： 每个开头的 1位 后面再任取1位 p(9,1)
        # 三位数， 开头九位，后面扔去两位 p(9,2)
        # i 位数， 开头1位，后面 p(9, i-1)
        for i in range(1, n_digit): 
            result -= n_digit_no_repeat(i)
        for i in range(n_digit):
            # when we fix the most significant digit, it 
            # can't be zero
            start = 0 if i else 1
            for j in range(start, digits[i]):
                if has_repeated(prefix * 10 + j):
                    continue
                # 比如处理  12345， prefix 来到 123， 前面那个是123已经定死了， 这三个数是不能取的，后面 所以在 7个里面取两个 p(7,2)
                if i != n_digit-1:
                    result -= permutation(10-i-1, n_digit-1-i)
                else:
                    # optmized from `result -= has_repeated(prefix*10+j)`
                    result -= 1
            prefix = prefix*10 + digits[i]
        return result + has_repeated(N)
