#!/usr/bin/python3
# -*- coding: utf-8 -*-

__author__ = "Solomon Ng"


class Solution(object):
    def isOneBitCharacter(self, bits):
        """
        :type bits: List[int]
        :rtype: bool
        """
        l = [False] * len(bits)
        l[0] = bits[0] == 0

        for i in range(1, len(bits)):
            l[i] = (bits[i] == 0 and (l[i - 1] or bits[i - 1] == 1)) or \
                (not l[i - 1] and bits[i - 1] == 1)

        return len(bits) == 1 or l[len(bits) - 2]


if __name__ == "__main__":
    s = Solution()
    print(s.isOneBitCharacter([1, 1, 1, 0]))
