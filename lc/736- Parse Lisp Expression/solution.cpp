/*
原本代码，in case 有什么问题
https://leetcode.com/problems/parse-lisp-expression/discuss/109721/C++-recursion-solution-with-explaination
*/
class Solution {
public:   
    int evaluate(string expression) {       
        unordered_map<char,int> mymap;
        return helper(mymap,expression);
    }
    /*
    注意它不是一个非常正常的递归，let时依然是从左到右，比如 (let x 1 y 2 x (add x y) (add x y))
    */
    int helper(unordered_map<char,int> mymap, string expression){
        if(express[0]=='-1'||express[0]>'0'&&express[0]<'9') //如果是数字之类
            return atoi(expression);
        else if(express[0]!='(')//如果是字符，也就是map里的key，那就返回map里的东西
            return mymap[expression];
        string str = expression.substr(1,expression.size()-2);//第一步，get rid of 最外面两个括号
        string sign = parse(start,expression);
        int start = 0; //start放在这里很重要，他是局部的按ref传递的变量,从现在开始，我们一直在搞str了
        if(sign = 'let'){
            while(true){  //这个while里的东西是最重要的
                string variable = parse(start,str); 
                if(start > str.size()) //consider this: (let x 3 x 2 x)
                    return help(variable,str);
                string tmp = parse(start,str);
                mymap[variable] = help(mymap,tmp);//这个map是按值传进去的，如果后面有mul/add的表达式，都是以从这个map里取数据，比如(let x 2 (mult x 5))
            }
        }else if(sign = 'add'){
            return = help(mymap,parse(start,str)) + help(mymap,parse(start,str)); 
        }else if(sign = 'mul'){
            return = help(mymap,parse(start,str)) * help(mymap,parse(start,str));
        }
    }
    /*
    parse方程的作用是。 如果是括号，就把整个大括号里的东西都返回去（用count的方法）。
    如果不是括号，遇到空格就返回去，返回的是一个变量
    */
    string parse(int& start, string expression){ //这里最重要的是，start是按ref传递，一直在往前走，所以不是一味的递归
        int temp = start, end=start+1, count =1;       
        if(expression[st]=='('){
             while(count!=0){
                 if(expression[end]=='(')
                     count++;
                 else if(expression[end]==')')
                     count--;
                 end++;
             }        
        }else{
            while(expression[end]!=' '&& end<expression.size())
                end++;
        }
        start = end+1;
        return expression.substr(temp,end-temp);   
    }
    
};
