#!/usr/bin/python2
# -*- coding: utf-8 -*-

__author__ = "Solomon Ng"


class Solution:
    def maximumGap(self, num):
        l=len(num)
        if l<2:
            return 0

        minNum=min(num)
        maxNum=max(num)
        gap=(maxNum-minNum-1)/(len(num)-1)+1

        bucketMin=([None]*l)
        bucketMax=([None]*l)
        for i in num:
            idx=(i-minNum)/gap
            if bucketMin[idx]==None or bucketMin[idx]>i:
                bucketMin[idx]=i
            if bucketMax[idx]==None or bucketMax[idx]<i:
                bucketMax[idx]=i

        prev=minNum
        maxGap=0
        for i in range(l):
            if bucketMin[i]!=None:
                if bucketMin[i]-prev>maxGap:
                    maxGap=bucketMin[i]-prev

                prev=bucketMax[i]

        return maxGap


if __name__=="__main__":
    s=Solution()
    print s.maximumGap(range(5000))
