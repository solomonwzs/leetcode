#!/usr/bin/python2
# -*- coding: utf-8 -*-

__author__ = "Solomon Ng"

from utils import FenwickTree


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
        '''
        lower <= sum[i, j] = sum[j] - sum[i-1] <= upper
        lower + sum[i-1] <= sum[j] <= upper + sum[i-1]
        '''
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
    print s.countRangeSum([-2, 5, -1], 0, 2)
    print s.countRangeSum([1, 2, 3], 6, 6)
    # print s.countRangeSum([0], 0, 0)
