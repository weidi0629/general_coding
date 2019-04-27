class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, vector<int>> group;
        vector<int> prev(dict.size(), 1); // use single char as prefix by default
        for (int i = 0; i < dict.size(); ++i) {
            auto abbr = abbrev(dict[i], prev[i]);
            group[abbr].push_back(i);
        }
        
        vector<string> result(dict.size());
        for (auto &p:group) {
            for (int i:p.second) {              
                while (true) {
                    unordered_set<int> dup;
                    for (int j:p.second) {
                        if (i == j) {
                            continue;
                        }
                        if (result[i] == result[j]) {
                            dup.insert(j);
                        }
                    }
                    if (dup.empty()) {
                        break;
                    }
                    dup.insert(i); // change i as well
                    for (int k:dup) {
                        result[k] = abbrev(dict[k], ++prev[k]);
                    }
                }
                result[i] = result[i].empty() ? p.first:result[i]; // use default abbrevation if no change
            }
        }
        return result;
    }
    
    
    string abbrev(string &str, int k) { // k is length of prefix
        if (str.size() - k <= 2) {
            return str;
        }
        return str.substr(0, k) + to_string(str.size()-k-1) + str.back();
    }
};
