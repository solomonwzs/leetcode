#!/usr/bin/python3
# -*- coding: utf-8 -*-

__author__ = "Solomon Ng"


class Solution(object):
    def __init__(self):
        self.__res = [0] * 10001
        for i in range(1, 10001):
            s = str(i)
            if s.find("0") != -1:
                continue

            ok = 1
            for j in s:
                if i % (ord(j) - ord('0')) != 0:
                    ok = 0
                    break
            self.__res[i] = ok

    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        res = []
        for i in range(left, right + 1):
            if self.__res[i] == 1:
                res.append(i)
        return res


if __name__ == "__main__":
    s = Solution()
    print(s.selfDividingNumbers(1, 22))
