class TweetCounts:

    def __init__(self):
        self.a = defaultdict(list)

    def recordTweet(self, tn: str, time: int) -> None:
        bisect.insort(self.a[tn], time) # 插入数据后，依然保持list sorted
       
    def getTweetCountsPerFrequency(self, freq: str, tn: str, startTime: int, endTime: int) -> List[int]:
        delta = 60 if freq == 'minute' else 3600 if freq == 'hour' else 86400
        i = startTime
        res = []
        while i <= endTime:
            j = min(i + delta, endTime+1)
            res.append(bisect_left(self.a[tn], j) - bisect_left(self.a[tn], i)) # bisec_left 返回position
            i += delta
        return res
