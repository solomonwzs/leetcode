class FenwickTree(object):
    def __init__(self, n):
        self.sum_array = [0] * (n + 1)
        self.n = n

    def lowbit(self, x):
        return x & (-x)

    def add(self, i, delta):
        while i < self.n:
            self.sum_array[i] += delta
            i += self.lowbit(i)

    def sum(self, i):
        res = 0
        while i > 0:
            res += self.sum_array[i]
            i -= self.lowbit(i)
        return res


class Node(object):
    def __init__(self, n):
        self.num = n
        self.cnt = 0


class Solution(object):
    def __megre(self, left, right):
        res = []
        lp = 0
        rp = 0
        while lp < len(left) and rp < len(right):
            if left[lp].num <= right[rp].num:
                left[lp].cnt += rp
                res.append(left[lp])
                lp += 1
            else:
                res.append(right[rp])
                rp += 1

        while lp < len(left):
            left[lp].cnt += rp
            res.append(left[lp])
            lp += 1

        while rp < len(right):
            res.append(right[rp])
            rp += 1

        return res

    def __sort(self, nlist):
        if len(nlist) <= 1:
            return nlist
        else:
            mid = len(nlist) / 2
            left = self.__sort(nlist[0:mid])
            right = self.__sort(nlist[mid:])
            return self.__megre(left, right)

    def countSmaller0(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nlist = []
        for i in nums:
            nlist.append(Node(i))
        self.__sort(nlist)

        return [x.cnt for x in nlist]

    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        d = {}
        for i, num in enumerate(sorted(set(nums))):
            d[num] = i + 1

        tree = FenwickTree(len(nums))
        res = [0] * len(nums)
        for i in xrange(len(nums)-1, -1, -1):
            res[i] = tree.sum(d[nums[i]] - 1)
            tree.add(d[nums[i]], 1)

        return res


if __name__ == "__main__":
    s = Solution()
    print s.countSmaller([5, 2, 6, 1])
