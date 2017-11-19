#!/usr/bin/python3
# -*- coding: utf-8 -*-

__author__ = "Solomon Ng"

import bisect


class MyCalendar(object):
    def __init__(self):
        self.__p = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        if start > end:
            return False

        if len(self.__p) == 0:
            bisect.insort(self.__p, (start, end))
            return True

        # print(self.__p, (start, end))
        pos = bisect.bisect(self.__p, (start, end))
        if pos == 0:
            t = self.__p[0]
            if end <= t[0]:
                bisect.insort(self.__p, (start, end))
                return True
            else:
                return False
        elif pos == len(self.__p):
            t = self.__p[pos - 1]
            if start >= t[1]:
                bisect.insort(self.__p, (start, end))
                return True
            else:
                return False
        else:
            t0 = self.__p[pos - 1]
            t1 = self.__p[pos]
            if start >= t0[1] and end <= t1[0]:
                bisect.insort(self.__p, (start, end))
                return True
            else:
                return False


if __name__ == "__main__":
    m = MyCalendar()
    t = [[47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[8,13],[18,27]]
    for i in t:
        print(m.book(i[0], i[1]))
