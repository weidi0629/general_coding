/*
注意这题给了几个方程可以用
这题的题设是背地里一直call hasNext(), 如果返回true就call next()， call hasNext()是隐含条件. 所以每次需要在hasNext()里面做文章。 
注意因为输出的要求，一开始是倒过来存进去的。
*/

class NestedIterator {
private:
    stack<NestedInteger> nodes;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for(int i = size - 1; i >= 0; --i) {
            nodes.push(nestedList[i]);
        }
    }

int next() {
    int result = nodes.top().getInteger();
    nodes.pop();
    return result;
}

bool hasNext() {
    while(!nodes.empty()) {
        NestedInteger curr = nodes.top();
        if(curr.isInteger()) {
            return true;
        }
        
        nodes.pop();
        vector<NestedInteger>& adjs = curr.getList();
        int size = adjs.size();
        for(int i = size - 1; i >= 0; --i) {
            nodes.push(adjs[i]);
        }
    }
    
    return false;
    }
};
