class Solution {
public:
    string lastSubstring(string s){
        int i=0, sz =0, n =s.size(); // i: start, searching the same pattern
        for(int j=1; j<n;j++){ // j 也是一个start
            for(int sz=0;j+sz<n;sz++){
                if(s[i+sz]==s[j+sz]) continue; // 大家势均力敌，看下一个
                i =s[i+sz]>s[j+sz]?i:j; //如果不一样，如果以i开头大的，那j这个头已经没有用了，换下一个头看看，如果j大，那i这个头就改换了
                break;
            }
            if(j+sz==n) break;
        }
        return s.substr(i);
    }
};
