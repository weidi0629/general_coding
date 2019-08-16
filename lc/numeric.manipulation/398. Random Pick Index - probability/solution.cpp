/*
Actually, we could first consider following question:

You have a file consisting of characters. The characters in the file can be read sequentially, but the length of the file is unknown. How do you pick a character so that every character in the file has equal probability of being chosen?

For this problem we can take algorithm like this:

Draw the 1st char. If there is a second char, then we will hold 1st char by prob = 1/2, and replace the 1st char to 2nd char with prob = 1/2. After this step we suppose that the char is X now.

After then, if there is 3rd char, then we will hold the X with prob = 2/3 and replace X to 3rd char with prob = 1/3. Why do they hold the same prob to be picked?
Because:
Obviously, Prob(the 3rd char is picked) = 1/3;
Prob(the 2nd char is picked) = 1 * 1/2 * 2/3 = 1/3; // 第二个拿到，第一个没有，第三个没有（1-1/3）
Prob(the 1st char is picked) = 1 * 1/2 * 2/3 = 1/3; // 同上

So we can say that when we now has n chars and there is still another char in the file, we can pick the other char with prob= 1/(n+1), also keep original char with prob = n/(n+1), then we can secure each char is picked with same prob = 1/(n+1), because prob = 1 * 1/2 * 2/3 * ···· * n/(n+1) = 1/(n+1).

Now, go back to this problem. The thought is the same, when we meet some nums[i] == target, we can use above conclusion: we can pick the other char with prob= 1/(n+1), also keep original char with prob = n/(n+1), then we can secure each char is picked with same prob = 1/(n+1).

*/

class Solution {
vector<int> _nums;
public:
Solution(vector<int> nums) {
    _nums = nums;
}

int pick(int target) {
    int n = 0, ans = -1;
    for(int i = 0 ; i < _nums.size(); i++){
        if(_nums[i] != target) continue;
        if(n == 0){ans = i; n++;}
        else{
            n++;
            if(rand() % n == 0){ans = i;}// with prob 1/(n+1) to replace the previous index
        }
    }
    return ans;
}
};
