def suggestedProducts(self, A, word):
        A.sort()
        res, prefix, i = [], '', 0
        for c in word:
            prefix += c
            i = bisect.bisect_left(A, prefix, i) #只要A里面有string 的prefix 一样，就会返回第一个找到的位置
            res.append([w for w in A[i:i + 3] if w.startswith(prefix)])
        return res
