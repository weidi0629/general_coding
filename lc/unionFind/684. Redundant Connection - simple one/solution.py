  
def findRedundantConnection(self, edges):
    tree = ''.join(map(chr, range(1001)))  #这里测试tree里面一堆乱码，但是没有关系，who cares
    for u, v in edges:
        if tree[u] == tree[v]:
            return [u, v]
        tree = tree.replace(tree[u], tree[v]) #注意replace返回还是一个string,
        #This method returns a copy of the string with all occurrences of substring old replaced by new. If the optional argument max
        #is given, only the first count occurrences are replaced.
