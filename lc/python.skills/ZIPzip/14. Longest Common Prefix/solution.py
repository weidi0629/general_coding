if len(strs) == 0:
            return ""
        for i, group in enumerate(zip(*strs)):
            if(len(set(group)) >1): #group是横过来的每一个字符
                return strs[0][:i]
        return min(strs)
