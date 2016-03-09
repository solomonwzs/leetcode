class FenwickTree(object):
    def __init__(self, n):
        self.sum_array = [0] * (n + 1)
        self.n = n

    def lowbit(self, x):
        return x & (-x)

    def add(self, i, delta):
        while i <= self.n:
            self.sum_array[i] += delta
            i += self.lowbit(i)

    def sum(self, i):
        res = 0
        while i > 0:
            res += self.sum_array[i]
            i -= self.lowbit(i)
        return res
