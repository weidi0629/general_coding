nth_element(begin(cs), begin(cs) + cs.size() / 2, end(cs), [](vector<int> &a, vector<int> &b) {
    return (a[0] - a[1] < b[0] - b[1]);});
从开始到当中参数这段排序，后面就不管了，但保证后面的肯定比当中那个要小（大小depend on lambda逻辑）
