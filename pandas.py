# group by multiple col, count, and add two df
res =  tmpc.groupby(['IDNUM','FAdd','FSAdd']).count().add\
            (res.groupby(['IDNUM','FAdd','FSAdd']).count(),fill_value=0).reset_index()

df1 = df.copy() # deep copy is in default, deep copy means create a new object
df2 = df.copy(deep=false) # deep is false, means it if a reference

np.where(condition) # 告诉你满足条件的位置，二维的

squeeze() #把array中分散的元素挤到一起去：array([['1'],['2'],['2']], dtype=object) ==> array(['1', '2', '2'], dtype=object)

df.iloc #使用index num(数字)来做sliding， 而df.loc是用column名字


