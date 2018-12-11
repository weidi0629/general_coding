/*
这题跟LC上c++版本有所出入，但大致想法一样的，就是要将map里的数跟used这个list连接起来，这里用Iterator进行连接。get方程里面第一次写的不对，进行重写。

*/

class LRUCache {
public:
       
    LRUCache(int capacity) {
        this->cap = capacity;      
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        else{
            return mp[key].second.first;
            touch(key);
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            touch(key);
            return;   
        }
        else{
            //if (used.size()==cap){ // 这里这段思路不是很清楚, 重写
                //used.pop_bottom();
                ///used.push(key);
                ///mp[key]=make_pair(value,used.begin); //    
            //}
            ///else{
              //  mp[key]=make_pair(value,used.begin);
               // touch(key);
            //}
            if(mp.size()==cap){ //唯一要做的就是把mp里面删掉
                mp.erase(used.back());//注意list的这个方法
                used.pop_back();//注意list的这个方法
            }
            used.push_front();
        }
        mp[key] = {value,used.begin()};
    }

typedef list<int> LI;
typedef pari<int,list<int>:iterator> PI;
typedef unordered_map<int,pair<int,int>> HPI;


private:

    void touch(int k){ //这题的关键就是将 map 跟这个used list连接起来，而这里连接用的就是iterator
        int key = mp[k].first;
        auto iter = mp[k].second.second;
        used.erase(iter);
        used.push_front(key); //注意list的这个方法
        mp[k].second.second = used.begin();
    }
    
PI used;
HPI mp;  
int cap;
    
};
