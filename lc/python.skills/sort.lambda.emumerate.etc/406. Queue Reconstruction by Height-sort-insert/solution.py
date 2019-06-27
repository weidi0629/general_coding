def reconstructQueue(self, people):
    people.sort(key=lambda (h, k): (-h, k))# 第一个参数大的在前，第二个参数小的在前 
    queue = []
    for p in people:
        queue.insert(p[1], p) #在第几个位置插入
    return queue
