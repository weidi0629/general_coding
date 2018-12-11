def isToeplitzMatrix(self, m):
        return all(m[i][j] == m[i+1][j+1] for i in range(len(m)-1) for j in range(len(m[0])-1))
#Or shorter and more pythonic.

    def isToeplitzMatrix(self, m):
        return all(r1[:-1] == r2[1:] for r1,r2 in zip(m, m[1:]))
 '''
 第一个版本还是比较直观的，第二个解释一下zip
 假设m : [[1, 2, 3, 4], [5, 1, 2, 3], [9, 5, 1, 2]]; n = [[5, 1, 2, 3], [9, 5, 1, 2]]
 zip(m,n)之后呢，就是就是m第一个跟n第一个  [1, 2, 3, 4] <--> [5, 1, 2, 3] 注意这不是原来的m里的第一第二个
 所以算法里 r1[:-1] 就是一直到倒数第二个  1,2,3 而 r2[1:0]就是从第二个开始算  也是123这是题设的转化
 另外注意的是，zip m的最后一个list [9,5,1,2], 而n没有跟他一起zip的元素，所以zip就取消--没有这一项
 '''
