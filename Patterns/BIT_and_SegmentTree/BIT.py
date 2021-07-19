class BIT:
    def __init__(self, n):
        self.size = n
        self.tree = [0 for _ in range(n+1)]

    def update(self, index, delta):
        while(index <= self.size):
            self.tree[index] += delta
            index += self.lowbit(index)

    def lowbit(self, x):
        return x & (-x)

    def queue(self, index):
        res = 0
        while(index > 0):
            res += self.tree[index]
            index -= self.lowbit(index)
        return res
