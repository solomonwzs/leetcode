#!/usr/bin/python2
# -*- coding: utf-8 -*-

__author__ = "Solomon Ng"

import bisect


class Solution(object):
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        dp = [float("-inf")]
        for i, j in sorted(pairs, key=lambda x: x[1]):
            idx = bisect.bisect_left(dp, i)
            if idx == len(dp):
                dp.append(j)
            elif j < dp[idx]:
                dp[idx] = j
        return len(dp) - 1


if __name__ == "__main__":
    s = Solution()
    # print s.findLongestChain([[1, 2], [2, 3], [3, 4]])
    print s.findLongestChain([[3, 4], [2, 3], [1, 2]])
