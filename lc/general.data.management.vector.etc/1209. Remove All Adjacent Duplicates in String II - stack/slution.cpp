/*
Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left 
and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

 
 
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
*/

/*
这题主要的问题，给一个string，同时间删去3个相同的的char的结果，过从左到右一个个找结果是一样的

比如 ceeeccabbbaa
同时删去 eee,bbb 得到 cccaaa再同时删去 ccc,aaa， 跟从左到右一点点找 先删去 eee, 再删去ccc,再bbb最后aaa结果是一样的
这样做避免把问题搞复杂了 

*/



string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stack = {{0, '#'}};
        for (char c: s) {
            if (stack.back().second != c) {
                stack.push_back({1, c});
            } else if (++stack.back().first == k)
                stack.pop_back();
        }
        string res = "";
        for (auto & p : stack) {
            res += string(p.first, p.second);
        }
        return res;
    }
