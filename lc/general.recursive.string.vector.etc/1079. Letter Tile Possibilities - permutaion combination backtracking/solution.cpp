/*
每个字母计数，每个字母都是一样的。count -- 表示取出来几个，backtracking.

第二种方法也是backtracking,不过是吧所有的都记录下来，比较straightforward
*/
class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> count(26,0);
        int res =0;
        for(auto t:tiles){
            count[t-'A']++;
        }
        helper(count,res);
        return res;    
    }
    
    void helper(vector<int> count, int& res){
        for(int i=0; i<26; i++){
            if(count[i] == 0)
                continue;
            res++;
            count[i]--;
            helper(count,res);
            count[i]++;
        }
    }
};



class Solution {
    private Set<String> set;

    public int numTilePossibilities(String tiles) {
        set = new HashSet<>();
        backtrack(tiles.toCharArray(), 0);
        return set.size();
    }

    private void backtrack(char[] chars, int i) {
        if (i >= 1) {
            set.add(String.valueOf(Arrays.copyOf(chars, i)));
        }
        
        if (i == chars.length) return;

        for (int j = i; j < chars.length; j++) {
            swap(chars, i, j);
            backtrack(chars, i + 1);
            swap(chars, i, j);
        }
    }

    private void swap(char[] chars, int i, int j) {
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }
}
