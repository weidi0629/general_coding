# group by multiple col, count, and add two df
res =  tmpc.groupby(['IDNUM','FAdd','FSAdd']).count().add\
            (res.groupby(['IDNUM','FAdd','FSAdd']).count(),fill_value=0).reset_index()

df1 = df.copy() # deep copy is in default, deep copy means create a new object
df2 = df.copy(deep=false) # deep is false, means it if a reference
