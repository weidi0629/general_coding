
vector<string> findOcurrences(string text, string first, string second) {
  vector<string> res;
  auto bigram = first + " " + second + " ";
  auto p = text.find(bigram);
  while (p != string::npos) {
    auto p1 = p + bigram.size(), p2 = p1; 
    while (p2 < text.size() && text[p2] != ' ') ++p2; //跳过那个size找空格
    res.push_back(text.substr(p1, p2 - p1));
    p = text.find(bigram, p + 1);
  }
  return res;
}





// 这个python的SOLUTION 也是简单易懂
def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        words = text.split()
        res = []
        if len(words) < 3:
            return res
        for i in range(len(words) - 2):
            if words[i] == first and words[i+1] == second:
                res.append(words[i+2])
        return res

