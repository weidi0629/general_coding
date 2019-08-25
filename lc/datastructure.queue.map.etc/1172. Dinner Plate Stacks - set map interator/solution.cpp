int c;
    map<int, vector<int>> m;
    set<int> available;

    DinnerPlates(int capacity) {
        c = capacity;
    }

    void push(int val) {
        if (!available.size())
            available.insert(m.size()); // 这里比较tricky，一开始可能想不到。考虑如果1-3列都满了，那available都给清空。然后加进来的就是4(m.size())
        m[*available.begin()].push_back(val); //这是记录这题的原因，学会使用 *interator, 表示实际的书
        if (m[*available.begin()].size() == c)
            available.erase(available.begin());
    }

    int pop() {
        if (m.size() == 0)
            return -1;
        return popAtStack(m.rbegin()->first);
    }

    int popAtStack(int index) {
        if (m[index].size() == 0)
            return -1;
        int val = m[index].back();
        m[index].pop_back();
        available.insert(index);
        if (m[index].size() == 0) // 删光了就不要了，跟上面的 available.insert(m.size())有关联
            m.erase(index);
        return val;
    }
