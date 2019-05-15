/*
https://www.geeksforgeeks.org/pattern-searching-using-suffix-tree/

general: Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of 
pat[] in txt[]. You may assume that n > m.
Preprocessing of text may become costly if the text changes frequently. It is good for fixed text or less frequently changing text though.


- preprocessing text to suffix tree

- search pattern in O(m), m: len(text)

- Compressed Trie 
  - Compress Trie is obtained from standard trie by joining chains of single nodes
  
- build a suffix tree from given text.
  - Generate all suffixes of given text.
  - Consider all suffixes as individual words and build a compressed trie.
  
- 然后就是用pattern 在compressed tree里面找


- 之后的引申
KMP Algorithm
Rabin Karp Algorithm
Finite Automata based Algorithm
Boyer Moore Algorithm
