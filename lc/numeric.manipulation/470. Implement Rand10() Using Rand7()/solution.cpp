/*
这题很厉害，下面英语是lee的解释，中文是自己的笔记。如果想不起来，慢慢看不要跳。
*/

/*
第一个方法跟后面是有联系的，虽然简单但是一定要搞清楚

Solution 0: Easy Solution with random 49
rand7() will get random 1 ~ 7
(rand7() - 1) * 7 + rand7() - 1 will get random 0 ~ 48
We discard 40 ~ 48, now we have rand40 equals to random 0 ~ 39.
We just need to return rand40 % 10 + 1 and we get random 1 ~ 7.

In 9/49 cases, we need to start over again.
In 40/49 cases, we call rand7() two times.

Overall, we need 49/40*2 = 2.45 calls of rand7() per rand10().
*/
 
C++:

    int rand10() {
        int rand40 = 40;
        while (rand40 >= 40) {
            rand40 = (rand7() - 1) * 7 + rand7() - 1;
        }
        return rand40 % 10 + 1;
    }
Python:

    def rand10(self):
        rand40 = 40
        while rand40 >= 40:
            rand40 = (rand7() - 1) * 7 + rand7() - 1
        return rand40 % 10 + 1

/*
Intuition of Improvement:
Solution 0 is a good answer and you may pass a interview with this solution.
The average call of rand7 here is 2.45 calls.

However, we may think about, what is the limit?
Is that possible to get an average of 2 calls.


What is the Limit
It may seem impossible, but unfortunately, even average 2 is still far from the best answer.

The problem is that you generate 49 random states, waste 9 of them.
And we arrange the rest 40 states into 10 states.
You can see that in that solution,
80% of random states waste and we satisfy with only 20% efficiency.

//下面这个公式稍微有点疑惑， 如果各数 x 等于 7 的a次方，又是10的b次方，那么运行a次随机方法（rand 7）如果可以得到b个随机数,那比例就是a/b
也就是 log7x(以7为底的x) / log7x(以10为底的x) 转化一下就是 log7/log10 
Did a quick math for the limit log10 / log7 = 1.1833,
which lead me to find the following solution.


Solution 1: instead of 49, we use bigger pow of 7:
rand10() will consume the generated random integer from stack cache.
If cache is empty, it will call function generate().

In generate(), it will generate an integer in range [0, 7^19].
7^19 = 11398895185373143, and close to an pow of 10. 这是7^19是随机数可以取的范围 
// 好比49时，大于40的不要。 这里大雨 xxxx40的不要，概率是极小的
So in 11398895185373140 / 11398895185373143 = 99.99999999999997% cases, it will generate at least 1 integer.
// 如果是 10000000000000000，也起码有16个随机数可以取，因为每一个个位都是随机数加上去的。
And in 10000000000000000 / 11398895185373143 = 87.73% cases, it will generate at least 16 integers. 

N = 19 is the best we can choose in long integer range,
and N = 7 is another good choice for 32 bits integer range.

This solution got average 1.199 calls, it's really close to theoretic limit.
*/
C++:

    stack<int> cache;
    int rand10() {
        while (cache.size() == 0) generate();
        int res = cache.top(); cache.pop();
        return res;
    }

    void generate() {
        int n = 19;
        long cur = 0, range = long(pow(7, n));
        // 这里的i是从0开始的，理论上最多也就是加到 pow(7,i)
        for (int i = 0; i < n; ++i) cur += long(pow(7, i)) * (rand7() - 1);
        while (cur < range / 10 * 10) {// 这里除以10乘以10是去掉个位那个数
            cache.push(cur % 10 + 1); // 这个是跟49那个一样，取个位的那个
            cur /= 10;// 又要取下一个个位
            range /= 10;//ranage缩小 
        }
    }

