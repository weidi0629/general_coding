# group by multiple col, count, and add two df
res =  tmpc.groupby(['IDNUM','FAdd','FSAdd']).count().add\
            (res.groupby(['IDNUM','FAdd','FSAdd']).count(),fill_value=0).reset_index()
