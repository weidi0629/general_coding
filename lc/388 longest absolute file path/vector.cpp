/*
1. 注意题意是path to file, 所以folder不算的
2 注意 \n每个只有一次，用\t来表示是多少sub folder。 所以可以不用递归
*/

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> lines = split(input);
        vector<int> lens(lines.size()+1,0);
        int maxlen = INT_MIN;
        for(auto line:lines){
            size_t pos = line.find_last_of('\t');  // 注意 \n是一个整体, 找不到的话返回string::npos
            int lev = (pos==string::npos)?0:pos+1;
            if(line.find('.') == string::npos){ // not file,根据题设，需要path to file,这里只从上一层的pareant更新
                lens[lev+1] = lens[lev] + line.size() - lev; // '/t'的长度不算
            }else{ //找到file，找最长的
                maxlen = max(maxlen,int(lens[lev]+line.size()-lev)); // 注意c++也有int(xxx)用法
            }
        }
        return maxlen;
    }
    
private:
    vector<string> split(string& input){
        istringstream ssi(input);
        vector<string> lines;
        string line;
        while(getline(ssi,line,'\n')) lines.push_back(line); // getline(input,str,delim) input	-	the stream to get data from;str	-	the string to put the data into;delim	-	the delimiter character
        return lines;
    }
};



