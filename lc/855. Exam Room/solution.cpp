class ExamRoom {
public:
    vector<int> s; 
    int n; 
    ExamRoom(int N) {
        n = N ;
    }
    
    int seat() {
        if(s.size()==0){ // 一个人都没有
            s.push_back(0);
            return 0;
        }
        //开始寻找整个里面的最大值
        int d = max(s[0],n-1-s[s.size()-1]); //第一个跟最后一个的距离先取出来
        for(int i=0; i<n; i++) d = max(d,(s[i+1]-s[i])/2);
        //找到最大的以后，开始插入
        
        if(s[0]==d){ //如果是第一个，是不用除以2的,新来的人直接除以2就行了
                s.insert(s.begin(),0);
                return 0;
            }
        
        for(int i = 0; i< s.size()-1; i++){      
            if((s[i+1] -s[i])/2 == d){
                s.insert(s.begin()+i+1, (s[i]+s[i+1])/2);
                return s[i+1];
            } 
        }
        s.push_back(n-1); // 最大是最后一个，那就坐最后一个位置
        return n-1;
    }
    
    void leave(int p) {
        for(int i=0; i<s.size(); i++){
            if(s[i] == p) // erase 是按位置
                s.erase(s.begin()+i);
        }
    }
};
