
if len(strs) == 0:
            return ""
        for i, group in enumerate(zip(*strs)): # zip的输出是tuple ('w','w','g')
            if(len(set(group)) >1): #group是横过来的每一个字符, set 能去掉重复
                return strs[0][:i]
        return min(strs)
