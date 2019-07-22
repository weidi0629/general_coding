/*
要组成二叉树，要么是临近的两个lafe，要么是人家干剩下的结果。 
这题还有个DP version,写在dp section里面了
*/
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0, n = A.size();
        vector<int> stack = {INT_MAX};
        for (int a : A) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;  
    }
};

// ############  503 

      vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        vector<int> stack, res(n,-1);
        for (int i = 0; i < n * 2; ++i) {
            while (stack.size() && A[stack.back()] < A[i%n]) {
                res[stack.back()] = A[i%n];
                stack.pop_back();
            }
            stack.push_back(i%n);
        }
        return res;
    }
