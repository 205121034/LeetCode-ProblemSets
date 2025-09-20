from collections import deque, defaultdict
from sortedcontainers import SortedList
from typing import List

class Router:

    def __init__(self, memoryLimit: int):
        self.cap = memoryLimit
        self.buf = deque()
        self.seenPkts = set()
        self.destTsMap = defaultdict(SortedList)

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        pkt = (source, destination, timestamp)

        if pkt in self.seenPkts:
            return False

        if len(self.buf) >= self.cap:
            os, od, ot = self.buf.popleft()
            self.seenPkts.remove((os, od, ot))
            self.destTsMap[od].remove(ot)
            if not self.destTsMap[od]:
                del self.destTsMap[od]

        self.buf.append(pkt)
        self.seenPkts.add(pkt)
        self.destTsMap[destination].add(timestamp)
        return True

    def forwardPacket(self) -> List[int]:
        if not self.buf:
            return []

        s, d, t = self.buf.popleft()
        self.seenPkts.remove((s, d, t))
        self.destTsMap[d].remove(t)
        if not self.destTsMap[d]:
            del self.destTsMap[d]
        return [s, d, t]

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        if destination not in self.destTsMap:
            return 0
        ts = self.destTsMap[destination]
        l = ts.bisect_left(startTime)
        r = ts.bisect_right(endTime)
        return r - l
