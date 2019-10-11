/*
  如过长的是trie里面树枝，也就是倒过来
   
   ----------------> 
  有个矮的正过来找
   --->|   a        | 
   如果找到了，并且 a 这段也是palindrome, 那就可以组成这样     ---><---------------- ， 整个就是个palindrome
   
   倒过来也是一样

   所以trienode内部要有个特殊地方
   1. 要有一个index表示自己是结束的点，并且是原数组哪个index，避免自己跟自己搞（如果题设允许，这步就可以免去）
   
   2. 正对上面第一个例子，矮的找长的。如果长的每一个点，在建立树的时候，都查一下，自己之后到末尾这段(a)是否是palindrome,如果是的就吧这条的index存
      进一个array里面。这样每个点都有一个arrary，矮的找到结束那个点，只要查一下arrary里面每条线就可以了。
      
  源代码：
  https://leetcode.com/problems/palindrome-pairs/discuss/79195/O(n-*-k2)-java-solution-with-Trie-structure
  用map的方法还没有仔细看：
  https://leetcode.com/problems/palindrome-pairs/discuss/79199/150-ms-45-lines-JAVA-solution

*/

private static class TrieNode {
    TrieNode[] next;
    int index;
    List<Integer> list;
    	
    TrieNode() {
    	next = new TrieNode[26];
    	index = -1;
    	list = new ArrayList<>();
    }
}
    
public List<List<Integer>> palindromePairs(String[] words) {
    List<List<Integer>> res = new ArrayList<>();

    TrieNode root = new TrieNode();
		
    for (int i = 0; i < words.length; i++) {
        addWord(root, words[i], i);
    }
		
    for (int i = 0; i < words.length; i++) {
        search(words, i, root, res);
    }
    
    return res;
}
    
private void addWord(TrieNode root, String word, int index) {
    for (int i = word.length() - 1; i >= 0; i--) {
        int j = word.charAt(i) - 'a';
				
        if (root.next[j] == null) {
            root.next[j] = new TrieNode();
        }
				
        if (isPalindrome(word, 0, i)) {
            root.list.add(index);
        }
				
        root = root.next[j];
    }
    	
    root.list.add(index); // 后面的空气也是palidrome
    root.index = index;
}
    
private void search(String[] words, int i, TrieNode root, List<List<Integer>> res) {
    for (int j = 0; j < words[i].length(); j++) {	
      // 长的找短的, 找到有的短的已经到头了，找到条件是： 短的到头（index不是-1），不是自己，长的后面半截也是palidrome
    	if (root.index >= 0 && root.index != i && isPalindrome(words[i], j, words[i].length() - 1)) { 
    	    res.add(Arrays.asList(i, root.index));
    	}
    		
    	root = root.next[words[i].charAt(j) - 'a'];
      	if (root == null) return;
    }
    
    // 短的找长的，s已经死了，root还有货
    for (int j : root.list) {
    	if (i == j) continue;
    	res.add(Arrays.asList(i, j));
    }
}
    
private boolean isPalindrome(String word, int i, int j) {
    while (i < j) {
    	if (word.charAt(i++) != word.charAt(j--)) return false;
    }
    	
    return true;
}
