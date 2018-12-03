


class AutocompleteSystem {
public:

    class TreeNode{
        public:
            unordered_map<char,TreeNode> child; //注意如果是复合类型的，用map而不是vector
            unordered_map<string, int> counts;  
    }

    TreeNode* root;
   
    /*structure cmp{ 这个定义错了
        bool cmp(pair<string s1,int n1>,pair<string s2,int n2>){
	    return  s1>s2||s1==s2&&n1>n2;
        }
    }*/

    structure comp{
	bool operator()(pair<string,int> a; pair<string,int>b){
	    return a.second<b.second ||  a.second=b.second && a.first>b.first;//次数更重要 
	}
    }

    void add(string s, int i){   // 怎么把root跟node练习起来
	//TreeNode* node(s[0],i); 这里错了，要下面那样连
	TreeNode* curr = root;
	root->child[s[0]] = i; 
	for(int i=1;i<s.size();i++){
	    char c=s[i];
	    if(curr->child.find(c) == curr->child.end()){ //没找到
		//counts[s] = i; 这里错了，注意child里面是个node，所以要新建一个node
		TreeNode* next = New TreeNode();
		next->counts[s] = i;
		curr->child[c] = next;
	    }else{
		TreeNode* next = curr->child[c]; //这里没有写，漏掉了
		next->counts[s] +=i;
	    }
	    curr = next;
	}

    }

    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TreeNode(); //这里进行初始
   	prefix = "";

	for(int i=0;i<sentences.size();i++)
	    add(sentences[i],times[i]);
		
    }

    string prefix = "";
    
    vector<string> input(char c) {
	if(c='#'){
	    add(prefix,1);
	    prefix = "";
	}
        prefix +=c;
	TreeNode* node = root->child[prefix[0]];//这里也错了
	TreeNode* curr = root;
	if(node == NULL) return {}; 
	for(int i=1;i<prifix.size();i++){ // start from begin
	    if(curr->child[prifix[i]] == NULL){
	        return {};
	    }
	    curr=curr->child[prifix[i]];
        } 
        auto count = curr->counts;
	priority_queue<pair<string,int>,cmp> pq; // 这个定义也错了
	priority_queue<pair<string,int>,vector<pair<string,int>>, comp> pq;
	for(auto c:count){
	    pq.insert(make_pair(c.key(),c.value()));
	}
        vector<string> res;
	for(int i=0;i<3;i++){
	    res.push_back(pq.front());
	    pq.pop();
	}
	return res;
    }
};



















