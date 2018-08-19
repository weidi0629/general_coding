this file records the utilities for use of language of C++ and Python,
should syncronize with github

update date: 20180819

using vs cmd to compile c++ in windows:
cl /EHsc hello.cpp   https://msdn.microsoft.com/en-us/library/ms235639.aspx

c++:
vector:
-sort vector
sort(A.begin(),A.end()

-last element in the vector
v.back()

-sum up all the elements in vector: 
int sum =accumulate(A.begin(), A.end(), 0);

-using {} to define a simple vector:
return {a,b}

set:
-make vector to set:
unordered_set<int> S(A.begin(), A.end());

-count
int c = S.count(a)

String& char:
- iterator through the string:
for (char c : w)

-add int to char is another char:
'a' + 1 == 'b'

-update string value by char:
w[2] = 'c'; // w is a string

map:
-declare a map:
unordered_map<char, int> m;

-assign value:
m[c] = m.size()

others:
-iterator through 2^i
int c = 1; c << 1

Python:
list:
-sum the ele in list:
sum(A)

set:
-list to set:
Set(A)

-list is interator:
[w for w in words if F(w) == F(p)]

dict:
-define a dict and assign:
d = {}  d['a'] = 5

-get the value from dict:
m.get(c,d) # m is a dict, d is the default value if c is not found in m

String&char:
-convert int to char:
char(97) # a is 97

-append a string with chars
"".join(chr(m[c] + 97) for c in w)  # it's chr, not char!

enumerate:
a = ['a','b','c'] 
emumerate(a) return (0,a);(1,b);(2,c);
 

traversal:
tree: (1,2)(1,3)(2,4)(2,5) //(a,b) : a->b
Inorder (Left, Root, Right) : 4 2 5 1 3
Preorder (Root, Left, Right) : 1 2 4 5 3
Postorder (Left, Right, Root) : 4 5 2 3 1
https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

c++ 
-val <--> node:
vector<TreeNode*> s;
new TreeNode(pre[0])  // pre is a array of int, val's values

-define:
TreeNode* node = new TreeNode(pre[i]);

python:
stack = [TreeNode(pre[0])]
node = TreeNode(v)
