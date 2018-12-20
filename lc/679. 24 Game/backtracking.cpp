class Solution {
public:
    bool res=false;
    bool judgePoint24(vector<int>& nums) {
        vector<double> numsd;
        for(auto n:nums) numsd.push_back(n);
        backtracking(numsd);
        return res;
    }
private:
    void backtracking(vector<double>& nums){
        if(res) return;
        if(nums.size()==1){
            if(nums[0]-24 < 0.001) return true;
            return; // 漏了这一句，到了1怎么都要return
        }else{
            vector<double> next; //新建一个数组存新的两两组合，之后要把原始的vector删掉这合成的两个
            for(int i=0;i<nums.size();i++) // 没有顺序的遍历所有两两的组合，这样比较经济
                for(int j=0;j<i;j++){
                    double n1 = nums[i], n2 = nums[j];
                    next = {n1+n2,n1-n2,n2-n1,n1*n2};
                    if(n1!=0)
                        next.push_back(n2/n1);
                    if(n2!=0)
                        next.push_back(n1/n2);
                    //这里开始backtracking的步骤:减去->tracking->加回来
                    nums.erase(nums.begin()+i); 
                    nums.erase(nums.begin()+j);
                    for(auto nx:next){
                        nums.push_back(nx);
                        backtracking(nums);
                        nums.pop_back();
                    }
                    nums.insert(nums.begin()+i,n1); //加回来
                    nums.insert(nums.begin()+j,n2); //加回来
                }
            
        }
    }
};
