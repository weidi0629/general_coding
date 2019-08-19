/*
比如 3+2*4， 如果是按正常string 顺序往下面找，找到*,4还没有找到。所以在找到4的时候，应该*已经记录下来了。如果不是*/, 在stack里面出来的值默认是加的
*/

public class Solution {
public int calculate(String s) {
    int len;
    if(s==null || (len = s.length())==0) return 0;
    Stack<Integer> stack = new Stack<Integer>();
    int num = 0;
    char sign = '+';  // 先给定义了一个符号，这个可以把后面的符号都延后一个
    for(int i=0;i<len;i++){
        if(Character.isDigit(s.charAt(i))){
            num = num*10+s.charAt(i)-'0';
        }
        if((!Character.isDigit(s.charAt(i)) &&' '!=s.charAt(i)) || i==len-1){
            if(sign=='-'){  // 如果之前的符号是加减，就push进去，可以形成延后
                stack.push(-num);
            }
            if(sign=='+'){
                stack.push(num);
            }
            if(sign=='*'){
                stack.push(stack.pop()*num);
            }
            if(sign=='/'){
                stack.push(stack.pop()/num);
            }
            sign = s.charAt(i);
            num = 0;
        }
    }

    int re = 0;
    for(int i:stack){ // 在stack 里面的值默认都是加的
        re += i;
    }
    return re;
}
























