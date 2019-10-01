/*
首先记住 list.erase(iterator) 是 O(1)的。
那就需要一个bookkeeping 来记录这些iterator跟key的关系。
而正在maintain 这个 leaset recent use的，是这个list
*/

int size;
list<int> lru;                              // MRU ... LRU
unordered_map<int, list<int>::iterator> mp; // key -> iterator
unordered_map<int, int> kv;                 // key -> value

LRUCache(int capacity) : size(capacity) {}
int get(int key) {
    if (kv.count(key) == 0) return -1;
    updateLRU(key);
    return kv[key];
}
void put(int key, int value) {
    if (kv.size() == size && kv.count(key) == 0)
        evict();
    updateLRU(key);
    kv[key] = value;
}
void updateLRU(int key) {
    if (kv.count(key)) 
        lru.erase(mp[key]); // iterator 的 erase 是 O(1)
    lru.push_front(key);
    mp[key] = lru.begin(); // iterator 是指针，之后虽然value给压下去了，这个iterator也跟着一起下去，所以等于是 key -> 位置
}
void evict() {
    mp.erase(lru.back());
    kv.erase(lru.back());
    lru.pop_back();
}



