/*
找括号进stack, 下面这个是常规的套路。
括号展开问题，就是栈的问题。

分析：遇到左括号了就使用栈保存之前的数据，遇到右括号了，就出栈拼接两个字符串。
*/
class Solution {
public:
    string reverseParentheses(string s) {
        int n= s.size();
        string tmp;
        stack<string> st;
        for(auto c:s){
            if(c=='('){
                st.push(tmp);
                tmp.clear();
            }else if(c==')'){
                string pre;
                if(!st.empty()){
                    pre = st.top();
                    st.pop();
                    std:reverse(tmp.begin(),tmp.end());
                    pre += tmp;
                    tmp.swap(pre);
                }
            }else{
                tmp += c;
            }
        }
        return tmp;
    }
};

class Solution {
public:
    string reverseParentheses(string s) {
        int n= s.size();
        int i=0, cnt=1;
        while(s[i]!='('&&i<n)
            i++;
        if(i==n){
            return s;
        }
        int j;
        for(j=i+1;j<n;j++){
            if(s[j] == '(')
                cnt++;
            else if(s[j] == ')')
                cnt--;
            if(cnt ==0)
                break;
        }
        
        string head = s.substr(0,i);

        string tail = s.substr(j+1);
 
        string content =  reverseParentheses(s.substr(i+1,j-i-1)); 
        reverse(content.begin(),content.end());
        s = head+content+reverseParentheses(tail);
        return s;

    }
};
