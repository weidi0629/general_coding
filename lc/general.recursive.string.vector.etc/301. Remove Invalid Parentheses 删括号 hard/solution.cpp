/*
这题在解析时最大的疑问是为何j不能从0开始。有这个疑问主要是还是对recursion的没有理解到位，看google doc里的图。
在代码里的拆分
if(s[j]==p[1-rev]  首先要找到 ")"
&& (j==sj  // 这个感觉是为了保护边界 比如 ")("这种情况
|| s[j-1]!=p[1-rev])) // 这个是为了连续)的时候保证只删除第一个


*/

class Solution {
private:
vector<string> res;
string p={'(',')'};
void helper(string& s, int si, int sj, int rev){
    int stn=0;
    for(int i=si;i<s.size();i++){
        if(s[i]==p[rev]) stn++;
        else if(s[i]==p[1-rev]) stn--;
        if(stn<0){
            for(int j=sj;j<=i;j++){
                if(s[j]==p[1-rev] && (j==sj || s[j-1]!=p[1-rev])){
                    string t=s.substr(0,j)+s.substr(j+1);
                    helper(t, i, j, rev);
                }
            }
            return ;
        }
    }
    string rs=s;
    reverse(rs.begin(), rs.end());
    if(p[rev]=='('){
        helper(rs, 0, 0, 1-rev);
    }else{
        res.push_back(rs);
    }
}    
public:
    vector<string> removeInvalidParentheses(string s) {
        res.clear();
        helper(s, 0, 0, 0);
        return res;
    }
};
