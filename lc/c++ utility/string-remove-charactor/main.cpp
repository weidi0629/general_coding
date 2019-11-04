s.erase(remove(s.begin(), s.end(), '*'), s.end());

// remove之后新的string 就变短了，remove返回了新的string的end
// erase 删掉空余出来的部分
