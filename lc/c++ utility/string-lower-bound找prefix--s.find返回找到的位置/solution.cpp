int main()
{
    vector<string> vs = {"abc","bcd","cde","def","efg",};
	  auto it = vs.begin();
	  it = lower_bound(it, vs.end(), "cd");  // 即使是substring，只要是prefix它也会显示找到并返回，比如这里就找到cde
    std::cout << *it;
    
    string s = "abcde";
    auto i = s.find(abc); // 找到的话就会返回第几个位置，找不到就是end 一个很长的数字。在 problem 1268 lee的答案，他用 if(s.find(cur)) break;
    来表示没有在第一点找到cur
    
    return 0;
}
