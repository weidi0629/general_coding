/*
题设
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate 
number must exist. Assume that there is only one duplicate number, find the duplicate one.

这题关键是知道重复的点就是循环的入口，下面是简单的说明为什么
If there is no duplicate in the array, we can map each indexes to each numbers in this array. In other words, we can have a mapping 
function f(index) = number
For example, let's assume
nums = [2,1,3], then the mapping function is 0->2, 1->1, 2->3.
If we start from index = 0, we can get a value according to this mapping function, and then we use this value as a new index and, 
again, we can get the other new value according to this new index. We repeat this process until the index exceeds the array. 
Actually, by doing so, we can get a sequence. Using the above example again, the sequence we get is 0->2->3. 
(Because index=3 exceeds the array's size, the sequence terminates!)

However, if there is duplicate in the array, the mapping function is many-to-one.
For example, let's assume
nums = [2,1,3,1], then the mapping function is 0->2, {1,3}->1, 2->3. Then the sequence we get definitely has a cycle.
0->2->3->1->1->1->1->1->........ The starting point of this cycle is the duplicate number.

第二部就是算法的实现
To understand this solution, you just need to ask yourself these question.
Assume the distance from head to the start of the loop is x1
the distance from the start of the loop to the point fast and slow meet is x2
the distance from the point fast and slow meet to the start of the loop is x3
What is the distance fast moved? 2. What is the distance slow moved? 3. And their relationship?
x1 + x2 + x3 + x2
x1 + x2
x1 + x2 + x3 + x2 = 2 (x1 + x2)
Thus x1 = x3, that's the reason we reset fast to be 0.
Finally got the idea.

其实代码很简单
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l =0, r = nums.size();
        while(l<=r){
            int mid = l+(r-l)*0.5,cnt =0;
            for(auto n:nums){
                if(n<=mid) cnt++;
            }
            if(cnt<=mid){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
};
