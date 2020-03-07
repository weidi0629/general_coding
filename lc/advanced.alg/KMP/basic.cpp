https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
以上总体来说这个还是讲的很清楚的 

注意这个lps是给要pattern做的

算法的要点是做比较，比如：
TXT          AABAA...
PATTERN      AABAC        lps[0,1,0,1,0]
当上面的A跟下面的C相比时，说明C前面的跟上面的TXT 已经是一样的了。那pattern的lps同样适用于上面的txt。根据算法，现在j指到C，找到lps[j-1] ==1,
表示B后面的那个A，在前面有一个prefix是一样的，所以不用比了，这点很重要要想通（如果有两个一样，那两个不用比了。。），所以直接比j==1就行
TXT          AABAA...
PATTERN         AABAC        lps[0,1,0,1,0]

而在构建lps时，看下面的comment： 



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



















