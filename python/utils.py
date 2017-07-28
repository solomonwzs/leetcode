#!/usr/bin/python2
# -*- coding: utf-8 -*-

__author__ = "Solomon Ng"

import math


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

    def printf(self):
        height = 0
        m = self.n
        while m > 0:
            m = m / 2
            height += 1

        pm = [["+"] * (self.n + 1) for _ in xrange(height)]
        for i, num in enumerate(self.sum_array):
            if i != 0:
                pm[int(math.log(self.lowbit(i))/math.log(2))][i] = num

        for h in xrange(height - 1, -1, -1):
            empty = True
            for i in xrange(len(pm[h]) - 1, -1, -1):
                if pm[h][i] == "+":
                    if empty:
                        pm[h][i] = " " * 5
                    else:
                        pm[h][i] = "=" * 5
                elif pm[h][i] == "   | ":
                    empty = True
                else:
                    empty = False
                    pm[h][i] = "\033[0;32m[%3d]\033[0m" % pm[h][i]
                    for ih in xrange(h - 1, -1, -1):
                        pm[ih][i] = "   | "

        for h in xrange(height - 1, -1, -1):
            print "".join(pm[h][1:])
