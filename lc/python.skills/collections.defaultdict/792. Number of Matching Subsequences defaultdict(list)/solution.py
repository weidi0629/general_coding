def numMatchingSubseq(self, S, words):
    waiting = collections.defaultdict(list) # just like a map
    for w in words:
        waiting[w[0]].append(iter(w[1:]))  # iterator 的用法 
    for c in S:
        for it in waiting.pop(c, ()):  # 默认是()
            waiting[next(it, None)].append(it) # next iter, 如果没有就是None 
    return len(waiting[None])
