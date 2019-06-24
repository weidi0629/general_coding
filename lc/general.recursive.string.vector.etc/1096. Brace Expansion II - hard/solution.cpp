/*
case 0："s" 就是一个单独的string
case 1: {a} 大括号加一个正规表达式，正规表达式表示a可以是
case 2：{a,b,c,d} 里面都是正规表达式
case 3：a{a,b}{c,d} 里面都是连起来的单个或者花括号

** case 2 是最general的
case 3 里面都是case 1,0 
case 1 里面case 2
case 2 里面case 3

这个看似是无线循环,但其实 case 0 是个重要的断点

*/


class Solution {
    set<string> merge(set<string>&a, set<string>&b){
        if(a.size() == 0){
            return b;
        }
        if(b.size() == 0){
            return a;
        }
        set<string> ans;
        for(auto& v1: a){
            for(auto& v2: b){
                ans.insert(v1+v2);
            }
        }
        return ans;
    }
    
    //{a,b,c}
    set<string> parseRule1(const string& str, int& i){
        set<string> ans;
        i++;
        ans = parseRule2(str, i);
        i++;
        return ans;
    }
    //{a,b},{c,d}
    set<string> parseRule2(const string& str, int& i){
        set<string> ans;
        ans = parseRule3(str, i);
        while(i<str.length()){
            if(str[i] != ','){  // 如果不等于","， 那就是"}", "}"代表处理case1 的情况结束了
                break;
            }
            i++;
            set<string> tmp = parseRule3(str, i);
            ans.insert(tmp.begin(), tmp.end());
        }
        return ans;
    }
    //a{c,d}b{e,f}
    set<string> parseRule3(const string& str, int& i){
        set<string> ans;
        while(i < str.length()){
            if(str[i] == '}' || str[i] == ','){ // 因为case2是以 这两个符号进行结尾
                break;
            }
            if(str[i] == '{'){
                set<string> tmp = parseRule1(str, i);
                ans = merge(ans, tmp);
            }else{                              // 处理单个string， breaking point
                set<string> tmp;
                string tmpStr;
                while(i < str.length() && str[i] <= 'z' && str[i] >= 'a'){
                    tmpStr.push_back(str[i++]);
                }
                tmp.insert(tmpStr);
                ans = merge(ans, tmp);
            }
        }
        return ans;
    }
public:
    vector<string> braceExpansionII(string str) {
        int pos = 0;
        set<string> ans = parseRule2(str, pos);
        return vector<string>(ans.begin(), ans.end());
    }
};
