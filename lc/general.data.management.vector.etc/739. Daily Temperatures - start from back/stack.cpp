class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> tmp;
        vector<int> res(T.size(),0);
        for(int i = 0; i< T.size(); i++){
            while(!tmp.empty()&&T[i]>T[tmp.top()]){
                int j = tmp.top();
                tmp.pop();
                res[j] = i-j;
            }
            tmp.push(i);
        }
        return res;
    }
};
