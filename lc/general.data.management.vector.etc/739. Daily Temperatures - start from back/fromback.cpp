class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> tmp;
        vector<int> res(T.size(),0);
        for(int i = T.size()-1; i >= 0; i--){
            int j = i+1;
            while(j<T.size()&&T[i]>=T[j]){
                if(res[j]>0) 
                    j= j + res[j];
                else j = T.size(); 
            }
            if(j<T.size()) res[i] = j-i;
        }
        return res;
    }
};
