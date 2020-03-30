#1396. Design Underground System

class UndergroundSystem:
    def __init__(self):
        self.times = defaultdict(lambda : defaultdict(lambda : [0, 0]))
        self.transit = defaultdict(list)
        

    def checkIn(self, id: int, sname: str, t: int) -> None:
        self.transit[id].extend([sname, t])

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        srcname, srct = self.transit[id] # if list size and variables equals, can assign directly
        count, val = self.times[srcname][stationName] 
        self.times[srcname][stationName] = [count+1, val+t-srct] 
        self.transit[id] = []

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        count, val = self.times[startStation][endStation] 
        return val / count
        
  # https://stackoverflow.com/questions/8419401/python-defaultdict-and-lambda
