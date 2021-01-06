class RecentCounter:
    def __init__(self):
        self.queue = [-10000]
        self.prei = 0

    def ping(self, t: int) -> int:
        self.queue.append(t)
        while self.queue[self.prei] < t - 3000:
            self.prei += 1
        return len(self.queue) - self.prei

# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)


if __name__ == "__main__":
    recentCounter = RecentCounter()
    print(recentCounter.ping(1))
    print(recentCounter.ping(100))
    print(recentCounter.ping(3001))
    print(recentCounter.ping(3002))
