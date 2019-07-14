class Solution {
public:
    vector<int> relativeSortArray(vector<int>& A, vector<int>& B) {
        int key[1001], idx = 0; // 1001是个offset
        for (int i = 0; i < 1001; i++) key[i] = 1000+i; // 按值排序，i是小到大，所以小的在前，大的在后
        for (int b : B) key[b] = idx++; // 按位置排序，那个先到就领取小的idx
        sort(A.begin(), A.end(), [key](int c, int d){
            return key[c] < key[d];
        });
        return A;
    }
};


// python version

def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        k = {v: i for i, v in enumerate(B)}
        return sorted(A, key=lambda i: k.get(i, 1000 + i))
