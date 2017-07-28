#!/usr/bin/python2
# -*- coding: utf-8 -*-

__author__ = "Solomon Ng"


class Solution:
    def findMin(self, num):
        head=0
        last=len(num)-1

        while head<last-1 and num[head]>=num[last]:
            mid=(head+last)/2

            if num[mid]>num[last]:
                head=mid
            elif num[mid]<num[last]:
                last=mid
            else:
                last-=1


        if head==last:
            return num[head]
        else:
            return num[head] if num[head]<num[last] else num[last]


if __name__=="__main__":
    s=Solution()
    print s.findMin([3, 3, 1])
