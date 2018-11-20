/*There is a similar example in Java, but I wanted to share my solution using the new C++11 unordered_map and a list. 
The good thing about lists is that iterators are never invalidated by modifiers (unless erasing the element itself). 
This way, we can store the iterator to the corresponding LRU queue in the values of the hash map. 
Since using erase on a list with an iterator takes constant time, all operations of the LRU cache run in constant time.  */

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
			      if (cache.size() == _capacity) {
				    cache.erase(used.back());  // 主的里面不要了，那么辅助的used里面也不要了  
				    used.pop_back();
			  }
        used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;
    
    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);  // second.second指着used 里面的数。这句最重要，iter指着used里面的元素，用来作为删除的依据。
        used.push_front(key);
        it->second.second = used.begin(); // second.second是个iter,即使元素移动了，指着元素的指针会跟着他们一起移动。
    }
    
    HIPII cache;  // cache: [key,value, iter-> used list]，它是主的存储单元。
    LI used;  // used里面存的都是key 
    int _capacity;
};
