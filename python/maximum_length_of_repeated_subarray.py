#!/usr/bin/python3
# -*- coding: utf-8 -*-

__author__ = "Solomon Ng"


class Solution:
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        return max(self.__findLength(A, B), self.__findLength(B, A))

    def __findLength(self, A, B):
        maxLen = 0
        for i in range(len(A)):
            end = min(len(A), i + len(B))
            rlen = end - i
            if rlen < maxLen:
                break

            r = 0
            for j in range(i, end):
                if A[j] == B[j - i]:
                    r += 1
                else:
                    if r > maxLen:
                        maxLen = r
                    r = 0

            if r > maxLen:
                maxLen = r

        return maxLen


if __name__ == "__main__":
    s = Solution()
    print(s.findLength([1, 2, 3, 2, 1], [3, 2, 1, 4, 7]))
    print(s.findLength([0,0,0,0,1], [1,0,0,0,0]))
