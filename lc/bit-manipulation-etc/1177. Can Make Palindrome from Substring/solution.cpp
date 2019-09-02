/*
这题死做时间复杂度很高。高级的方法，第一阶段先利用prefix。根据题意，我们只要知道某个范围内奇数的字符个数就可以。因为偶数可以‘may rearrange the substring’，
剩下的奇数字符，我们只要替换掉一半就可以。时间复杂度从n（每个字符的长度）降到 26
*/
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int len = s.length();
        vector<vector<int> > hash(len + 1, vector<int>(26, 0));
        for (int i = 0; i < len; i++)
        {
            hash[i + 1].assign(hash[i].begin(), hash[i].end());
            hash[i + 1][s[i] - 'a']++;
        }
        int qlen = queries.size();
        vector<bool> ans;
        for (int i = 0; i < qlen; i++)
        {
            int count = 0;
            for (int j = 0; j < 26; j++) count += (hash[queries[i][1] + 1][j] - hash[queries[i][0]][j]) % 2; //算奇偶
            ans.push_back(count / 2 <= queries[i][2]);
        }
        return ans;
    }
};

/*
进一步，用bit manipulation 跟异或。关键语句：
odds[i + 1] = odds[i] ^ 1 << s.charAt(i) - 'a'; 每次有新的过来，都会跟原来取反。比如第一次来该位置1，第二次变0，第三次又是1.
现在考虑范围 [i,j], 如果在i之前无论是0还是1，只要在 [i,j] 还是一样的，说明在[i,j]内出现的偶数次。
所以最后我们只要找到范围内不一样的（异或结果是1的个数）
JAVA solution
*/
public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        List<Boolean> ans = new ArrayList<>(); 
        int[] odds = new int[s.length() + 1]; // odds[i]: within range [0...i) of s, the jth bit of odd[i] indicates even/odd of the count of (char)(j + 'a'). 
        for (int i = 0; i < s.length(); ++i)
            odds[i + 1] = odds[i] ^ 1 << s.charAt(i) - 'a'; // 在那一位反复交替变化
        for (int[] q : queries)
            ans.add(Integer.bitCount(odds[q[1] + 1] ^ odds[q[0]]) / 2 <= q[2]); // odds[q[1] + 1] ^ odds[q[0]] indicates the count of (char)(i + 'a') in substring(q[0], q[1] + 1) is even/odd.
        return ans;
    }
    
// 注意到 cpp里面没有 Integer.bitCount这个函数，一下是几个手动求的方法。

// 1. cpp 有内置函数可以使用
int main() 
{ 
   cout << __builtin_popcount (4) << endl; 
   cout << __builtin_popcount (15); 
  
   return 0; 
} 

//2 table 法， O(1), 这个方法简单易懂 
//这个表转化为 int 跟位数
  int num_to_bits[16] = {0, 1, 1, 2, 1, 2, 2, 3,  
                    1, 2, 2, 3, 2, 3, 3, 4};   
  
/* Recursively get nibble of a given number  
and map them in the array */
unsigned int countSetBitsRec(unsigned int num)  
{  
    int nibble = 0;  
    if (0 == num)  
        return num_to_bits[0];  
      
    // Find last nibble  
    nibble = num & 0xf;  // 找末四位
      
    // Use pre-stored values to find count  
    // in last nibble plus recursively add  
    // remaining nibbles.  
    return num_to_bits[nibble] +  
            countSetBitsRec(num >> 4);  
}    
    
    
// 方法3， Brian Kernighan’s Algorithm:    
    
 public: 
unsigned int countSetBits(int n) 
{ 
    unsigned int count = 0; 
    while (n) 
    { 
    n &= (n-1) ; 
    count++; 
    } 
    return count; 
} 
}; 
 
/*
算法原理是，每次减去1，会导致从最右到第一个1之间所有的0都取反。 比如
11000 -1 -> 10111 
两个再取一下&  11000 & 10111 = 10000 这个1 就没了
再来一次  10000 & 01111 = 00000 第二个1也没了

所以 *可循环的次数就是1的个数！
*/
    
    
    
    
    
    
    
    
    
