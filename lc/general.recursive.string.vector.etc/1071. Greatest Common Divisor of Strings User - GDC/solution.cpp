/* 如果对regular GDC 忘记了，看下另一个 regular gdc 文件 

这题是string 的 GDC，意思差不多。但因为string 不能做%, 所以只能做‘减法’

*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        if (str2.empty()) return str1;
        if (str1.substr(0, str2.size()) != str2) return "";
        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
};
