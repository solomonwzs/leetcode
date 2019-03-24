#!/usr/bin/python3
# -*- coding: utf-8 -*-
#
# @author   Solomon Ng <solomon.wzs@gmail.com>
# @date     2019-03-24
# @version  1.0
# @license  MIT


class Solution(object):
    def smallestRepunitDivByK(self, k):
        """
        :type k: int
        :rtype: int
        """
        if k % 2 == 0 or k % 5 == 0:
            return -1

        s = 1
        ans = 1
        p = 1
        while True:
            if s == 0 or s == k:
                return ans
            else:
                p = (p * 10) % k
                s = (s + p) % k
                ans += 1


if __name__ == "__main__":
    s = Solution()
    print(s.smallestRepunitDivByK(7))
