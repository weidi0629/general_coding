/*
两个要点， 数字结束一般就是一个新的 [ 开始
遇到 ] 就要准备返回 
*/

// recursive
// https://leetcode.com/problems/decode-string/discuss/87543/0ms-simple-C%2B%2B-solution

class Solution {
    int i = 0;
public:
    bool isDigit(char c) {
        return c - '0' >= 0 && c - '0' <= 9;
    }
    string decodeString(string s) {
        string decoded = "", num = "";
        for (i; i < s.length(); i++) {
            if (isDigit(s[i])) {
                while(isDigit(s[i])) {
                    num += s[i++];
                }
                i++;
                int times = stoi(num);
                string temp = decodeString(s); // 管他里面是什么，递归了
                for (int i = 1; i <= times; i++) { 
                    decoded += temp;
                }
                num = "";
            }
            else if (s[i] == ']') { // 遇到 ] 就要返回
                return decoded;
            }
            else {
                decoded += s[i];
            }
        }
        return decoded;
    }
};



// stack: 
https://leetcode.com/problems/decode-string/discuss/87534/Simple-Java-Solution-using-Stack

        Stack<Integer> intStack = new Stack<>();
        Stack<StringBuilder> strStack = new Stack<>();
        StringBuilder cur = new StringBuilder();
        int k = 0;
        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                k = k * 10 + ch - '0';
            } else if ( ch == '[') {
                intStack.push(k);
                strStack.push(cur); // 这里很关键，这里的cur是一件带了之前的（类似于递归里面的东西，所以要清零），也就是2那里
                cur = new StringBuilder();
                k = 0;
            } else if (ch == ']') {
                StringBuilder tmp = cur;
                cur = strStack.pop();
                for (k = intStack.pop(); k > 0; --k) cur.append(tmp); // 2 总结cur
            } else cur.append(ch);
        }
        return cur.toString();


