/*
https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
以上总体来说这个还是讲的很清楚的 

注意这个lps是给要pattern做的

算法的要点是做比较，比如：
TXT          T:AABAA... 
PATTERN      P:AABAC    ->    lps[0,1,0,1,0]
假设此时比较到 T[4] !=P[4]
那按照naive方法，我们应该把P往右移一位，从T[1] 开始从头比较
      i    
T:AABAA... 
p: AABAC    
但这样只移动1位是非常浪费的，为什么呢，因为我们知道，从T[1..3] 跟P[0..2]肯定是不一样的，依据就是lps数组。在i之前，唯一可能T跟P相同的范围，就是
lps[i-1]的，这里的lps[3] = 1,所以我们可以直接跳到
      i    
T:AABAA... 
p:   AABAC    

下面这个例子，lps比较大，所以我们只能移动一位
T:AAAAB...  i=3
p:AAAB  lps[0,1,2,0]    
==>
T:AAAAB...
P: AAAB

注意算法里通过reset j来与i做比较，其实是向右移几位一个意思。


而在构建lps时，看下面的comment： 
*/


void computeLPSArray(char* pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) {  // if equal just going forward
            len++;  
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        {    
            // 如果不一样，注意在这个之前都是一样的，所以我们直接跳到 lps[len-1],看他之前这个有多少个prefix跟他一样。跳完只好回到while再判断
            // 如果这时相等，那这个跳回去的len也就是i的len。这个有点dp的感觉在里面.
            // 可以看后面的详解
            if (len != 0) { 
                len = lps[len - 1]; 
   
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

/*
详解lps的构建：
比如  
A A B A A B A A C
0 1 0 1 2 3 4 5 0

在C的时候，前面有五个字符都是一样的: AABAA 

|------->
A A B A A B A A C
     |-------->
现在想找一个prefix,结束在C之前那个A（下面的箭头）并且这个prefix后面那个字符是C。但下面箭头的A, 也就是上面箭头的A，我们知道上面箭头的长度：5，
所以只要找lps[5-1] 得到他的lps。
到了第二轮，就会检查它下面的数是否是C
     
*/



















