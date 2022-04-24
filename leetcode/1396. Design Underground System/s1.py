# OJ: https://leetcode.com/problems/design-underground-system/
# Author: github.com/punkfulw
# Time: O(1) 
# Space: O(N)
class UndergroundSystem:

    def __init__(self):
        self.time = defaultdict(list)
        self.info = defaultdict(list)

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.info[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        start, st = self.info[id]
        spend = t - int(st)
        self.time[(start, stationName)].append(spend)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        sum = 0.0
        for t in self.time[(startStation, endStation)]:
            sum += t
        return sum / len(self.time[(startStation, endStation)])
