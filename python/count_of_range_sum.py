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


class Solution(object):
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        nlist = [lower - 1, upper]
        si = 0
        for i in nums:
            si += i
            nlist += [si + lower - 1, si, upper + si]

        d = {}
        for i, num in enumerate(sorted(set(nlist))):
            d[num] = i + 1

        tree = FenwickTree(len(d))
        res = 0
        for i in xrange(len(nums) - 1,  -1, -1):
            tree.add(d[si], 1)
            si -= nums[i]
            res += tree.sum(d[upper + si]) - tree.sum(d[lower + si - 1])
        return res

    def countRangeSum0(self, nums, lower, upper):
        l = len(nums)
        sl = []
        s = 0
        r = 0
        for i in nums:
            s += i
            sl.append(s)
            if lower <= s and s <= upper:
                r += 1

        for i in xrange(1, l):
            for j in xrange(i, l):
                sl[j] -= nums[i-1]
                if lower <= sl[j] and sl[j] <= upper:
                    r += 1
        return r


if __name__ == "__main__":
    s = Solution()
    print s.countRangeSum([-2, 5, -1], -2, 2)
    # print s.countRangeSum([0], 0, 0)
