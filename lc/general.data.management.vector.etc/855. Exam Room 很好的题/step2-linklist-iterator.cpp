/*
看答案前要先理清思路：
建立一个linklist，里面存的是什么？ seat 号码
建link list的目的就是remove时候快，但remove要用的是iterator，所以建立一个map，是 位置 -> iterator
剧透一下，寻找最大值一个个来：
  首先找第一个，再找当中的，再找最后的。找什么？ 新的位置，是*新的*位置！！

*/

class ExamRoom {
    int N;
    list<int> seats;
    unordered_map<int, list<int>::iterator> hash_map;
public:
    ExamRoom(int N) {
        this->N = N;
    }
    
    int seat() {
        if (seats.empty())
            return seats.push_back(0), hash_map[0] = seats.begin(), 0;
        int last = -1, dist, val;
        list<int>::iterator pos;
        for (auto it = seats.begin(); it != seats.end(); ++it) {
            if (last == -1)
                dist = *it, pos = it, val = 0;
            else if ((*it - last) / 2 > dist)
                dist = (*it - last) / 2, pos = it, val = (*it + last) / 2;
            last = *it;
        }
        if (N - 1 - seats.back() > dist)
            pos = seats.end(), val = N - 1;
        return hash_map[val] = seats.insert(pos, val), val;
    }
    
    void leave(int p) {
        seats.erase(hash_map[p]);
    }
};
