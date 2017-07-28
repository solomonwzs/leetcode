#!/usr/bin/python2
# -*- coding: utf-8 -*-

__author__ = "Solomon Ng"


class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        dp = [[-1] * l for i in xrange(l)]

        def __max(i, j):
            if i > j:
                return 0
            if dp[i][j] >= 0:
                return dp[i][j]

            xleft = 1 if i - 1 < 0 else nums[i - 1]
            xright = 1 if j + 1 == l else nums[j + 1]
            for x in xrange(i, j + 1):
                tmp = __max(i, x - 1) + xleft * nums[x] * xright + \
                    __max(x + 1, j)
                dp[i][j] = max(dp[i][j], tmp)

            return dp[i][j]

        return __max(0, l - 1)


if __name__ == "__main__":
    s = Solution()
    print s.maxCoins(range(100) + range(100))
