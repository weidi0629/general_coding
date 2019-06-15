public int countDigitOne(int n) {
  int count = 0;
    
  for (long k = 1; k <= n; k *= 10) {
    long r = n / k, m = n % k;
    // sum up the count of ones on every place k
    count += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
  }
    
  return count;
}

/*
Solution explanation:
这题主要考虑的是每一位上的计数。比如个位， n = 21, 个位就出现 20次1， n=30+, 个位就出现三十次1，这是基本思想  

Let's start by counting the ones for every 10 numbers...

0, 1, 2, 3 ... 9 (1)

10, 11, 12, 13 ... 19 (1) + 10

20, 21, 22, 23 ... 29 (1)

...

90, 91, 92, 93 ... 99 (1)

100, 101, 102, 103 ... 109 (10 + 1)

110, 111, 112, 113 ... 119 (10 + 1) + 10

120, 121, 122, 123 ... 129 (10 + 1)

...

190, 191, 192, 193 ... 199 (10 + 1)

1). If we don't look at those special rows (start with 10, 110 etc), we know that there's a one at ones' place in every 10 numbers, there are 10 ones at tens' place in every 100 numbers, and 100 ones at hundreds' place in every 1000 numbers, so on and so forth.

Ok, let's start with ones' place and count how many ones at this place, set k = 1, as mentioned above, there's a one at ones' place in every 10 numbers, so how many 10 numbers do we have?

The answer is (n / k) / 10.

Now let's count the ones in tens' place, set k = 10, as mentioned above, there are 10 ones at tens' place in every 100 numbers, so how many 100 numbers do we have?

The answer is (n / k) / 10, and the number of ones at ten's place is (n / k) / 10 * k.

Let r = n / k, now we have a formula to count the ones at k's place: r / 10 * k

2). So far, everything looks good, but we need to fix those special rows, how?

We can use the mod. Take 10, 11, and 12 for example, if n is 10, we get (n / 1) / 10 * 1 = 1 ones at ones's place, perfect, 
but for tens' place, 
we get (n / 10) / 10 * 10 = 0, that's not right, there should be a one at tens' place! 
Calm down, from 10 to 19, we always have a one at tens's place, let m = n % k, 
the number of ones at this special place is m + 1, so let's fix the formula to be:

r / 10 * k + (r % 10 == 1 ? m + 1 : 0)

比如 n = 2176, 现在处理第二个1的情况。 现在k = 100， r = 21, 21%10 == 1, 所以我们现在取到了这个1的情况，那这个1应该要加几个数？ 只要是这个1打头的，
所有的数都应该算进去(100 to 176)，那就是n%100 => 2176%100 = 176 + 1 (100自己)  


3). Wait, how about 20, 21 and 22?

Let's say 20, use the above formula we get 0 ones at tens' place, but it should be 10! How to fix it? We know that once the digit is larger than 2, we should add 10 more ones to the tens' place, a clever way to fix is to add 8 to r, so our final formula is:

(r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0)

注意加号前半段 (r + 8) / 10 * k 跟后半段 (r % 10 == 1 ? m + 1 : 0)是不可能同时满足的。
后半段是处理 2176 这种有1的半吊子的情况，
而前半段，如果2276这种，那第二个2已经过10了，那十个都应该给它加上去（其实这里加上的也不是是个，而是10*k，100-199一百个数）

*/

