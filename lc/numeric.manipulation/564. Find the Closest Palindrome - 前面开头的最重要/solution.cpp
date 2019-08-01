/*
Let's build a list of candidate answers for which the final answer must be one of those candidates. 
Afterwards, choosing from these candidates is straightforward.

If the final answer has the same number of digits as the input string S, then the answer must be the middle digits + (-1, 0, or 1) 
flipped into a palindrome. For example, 23456 had middle part 234, and 233, 234, 235 flipped into a palindrome 
yields 23332, 23432, 23532. Given that we know the number of digits, the prefix 235 (for example) uniquely determines the corresponding 
palindrome 23532, so all palindromes with larger prefix like 23732 are strictly farther away from S than 23532 >= S.

If the final answer has a different number of digits, it must be of the form 999....999 or 1000...0001, 
as any palindrome smaller than 99....99 or bigger than 100....001 will be farther away from S.

像这种数据比大小的，注意开头的要比后面的重要。还有类似的有 402
*/

class Solution {
public:
    string nearestPalindromic(string n) {
        int l = n.size();
        set<long> candidates;
        // biggest, one more digit, 10...01
        candidates.insert(long(pow(10, l)) + 1);
        // smallest, one less digit, 9...9 or 0
        candidates.insert(long(pow(10, l - 1)) - 1);
        // the closest must be in middle digit +1, 0, -1, then flip left to right
        long prefix = stol(n.substr(0, (l + 1) / 2));
        for ( long i = -1; i <= 1; ++i ) {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (l & 1), p.rend());
            candidates.insert(stol(pp));
        }
        long num = stol(n), minDiff = LONG_MAX, diff, minVal;
        candidates.erase(num);
        for ( long val : candidates ) {
            diff = abs(val - num);
            if ( diff < minDiff ) {
                minDiff = diff;
                minVal = val;
            } else if ( diff == minDiff ) {
                minVal = min(minVal, val);
            }
        }
        return to_string(minVal);
    }
};
