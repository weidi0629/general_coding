/*
this code has not been compiled



*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(),half_len = (m+n+1)/2;
        if(m>n){
            swap(m,n);
            swap(nums1,nums2);
        }
        int imin=0, imax=m,i,j;
        while(imin<=imax){
            i=(imin+imax)/2;
            j = half_len -i;
            if(nums1[i]>nums2[j+1]&&i<m) // i is too big
                imax = i;
            else if (nums1[i+1]< nums2[j]) 
                imin=i;
        }
        // i is perfect
        int left_max,right_min;
        if(i==0)
            left_max=nums2[j];
        else if(j==0)
            left_max=nums1[i];
        else 
            left_max = max(nums1[i],nums2[j];
        
        if((n+m)%2 == 1)
            return left_max;
        
        //if(i==0)//这里错了
        if (i==m)
            //right_min=nums2[0]; 这里也错了，注意这里j可能也在往前跑
            right_min=nums2[j+1];            
        if (j==n)
            right_min=nums1[i+1];
        else right_min = min(nums1[i+1],nums2[j+1]);
                          
        return (left_max+right+min)/2.0;
                    
    }
};
