#!/usr/bin/python3
# encoding: utf-8

aNum = set()

for i in range(32):
    n = str(2 ** i)
    aNum.add(''.join(sorted(n)))

class Solution:
    def reorderedPowerOf2(self, N):
        m = ''.join(sorted(str(N)))
        return m in aNum

if __name__ == '__main__':
    s = Solution()
    print(s.reorderedPowerOf2(46))
