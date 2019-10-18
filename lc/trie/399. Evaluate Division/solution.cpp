/*
本题有好几个要点：

主要思路是，把每个点都 assign 一个绝对值，最后的要求的结果就是把两个点的绝对值除一下，非常方便

mapping the node:
用一个map 来map string 对应node， 而node里面可以建立一些有用的我们要的东西。 这个非常实用   

parent建立
这题并没有要建立一个胖树，在建树的时候，每个点只 assign前面一个点的parent。这也是自己一开始在思考时，如果建立一个在同一个union里各个点的关系

如果一个点来过一个点没来过，来过的点就是没来过的parent，这样就不用来过的点所有跟他之前有关系的值了 

union
这里union是个重点中的重点 ， 比如现在 a= 6， b=2， a已经是b的三倍了（他们的值是在不同的union里面确立的），现在一个公式要求 a/b=5
所以不能简单的把 a设定成 b*5, 因为还要考虑所有在a这个union里面数都应该要变更，这样他们跟b相对的ratio就正确了
我们要得到一个比例，根据这个比例得到新的a, 也就是 b*5 / a:  (新的a / 旧的a，就是所有的union里的值要增加的比例) 

*/

class Solution {
    // date: 2016-09-12     location: Santa Clara City Library
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, Node*> map;
        vector<double> res;
        for (int i = 0; i < equations.size(); i ++) {
            string s1 = equations[i].first, s2 = equations[i].second;
            if (map.count(s1) == 0 && map.count(s2) == 0) {
                map[s1] = new Node();
                map[s2] = new Node();
                map[s1] -> value = values[i];
                map[s2] -> value = 1;
                map[s1] -> parent = map[s2];
            } else if (map.count(s1) == 0) {
                // 如果一个点来过一个点没来过，来过的点就是没来过的parent，这样就不用来过的点所有跟他之前有关系的值了 
                // 不用考虑 s2 union里面的值
                map[s1] = new Node();
                map[s1] -> value = map[s2] -> value * values[i];
                map[s1] -> parent = map[s2];
            } else if (map.count(s2) == 0) {
                map[s2] = new Node();
                map[s2] -> value = map[s1] -> value / values[i];
                map[s2] -> parent = map[s1];
            } else {
                unionNodes(map[s1], map[s2], values[i], map);
            }
        }
        for (auto query : queries) {
            if (map.count(query.first) == 0 || map.count(query.second) == 0 || findParent(map[query.first]) != findParent(map[query.second]))
                res.push_back(-1);
            else
                res.push_back(map[query.first] -> value / map[query.second] -> value);
        }
        return res;
    }
    
private:
    struct Node {
        Node* parent;
        double value = 0.0;
        Node()  {parent = this;}
    };
    
    void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map) {
        Node* parent1 = findParent(node1), *parent2 = findParent(node2);
        double ratio = node2 -> value * num / node1 -> value;
        for (auto it = map.begin(); it != map.end(); it ++)
            if (findParent(it -> second) == parent1)
                it -> second -> value *= ratio;
        parent1 -> parent = parent2;
    }
    
    Node* findParent(Node* node) {
        if (node -> parent == node)
            return node;
        node -> parent = findParent(node -> parent);
        return node -> parent;
    }
};
