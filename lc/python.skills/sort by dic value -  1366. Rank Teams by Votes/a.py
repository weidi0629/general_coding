'''
根据 dic's value 进行排序， 用 .get就可以
注意这题本身也很好， count 行是每一个人，列是每一个rank，根据题意排序就好
'''
 
 def rankTeams(self, votes):
        count = {v: [0] * len(votes[0]) + [v] for v in votes[0]}
        for vote in votes:
            for i, v in enumerate(vote):
                count[v][i] -= 1
        return ''.join(sorted(votes[0], key=count.get))
