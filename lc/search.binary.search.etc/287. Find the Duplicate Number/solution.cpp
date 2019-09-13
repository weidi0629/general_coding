/*
这题常规做法是用数学来做但是这个bianry search 的方法也非常的好
Basically, if there is not duplicated number at all, count number smaller than mid and larger than mid should be equal. But when we got duplicated one, more number would be at duplicated half. So we keep narrowing down scale. e.g. 1, 1, 3,2,4
we kick out 4 first, then 3, then 2, then we got 1.
definitely a upvote!
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
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
