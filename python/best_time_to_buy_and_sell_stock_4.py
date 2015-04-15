class Solution(object):
    def maxProfit(self, k, prices0):
        if len(prices0)<2:
            return 0

        slope=1 if prices0[0]<prices0[1] else -1
        prev=prices0[1]
        prices=[prices0[0]]
        for p in prices0[2:]:
            if slope==1 and prev>p:
                slope=-1
                prices.append(prev)
            elif slope==-1 and prev<p:
                slope=1
                prices.append(prev)
            prev=p
        prices.append(prev)
        if prices[0]>=prices[1]:
            prices.pop(0)
        if len(prices)>1 and prices[-2]>prices[-1]:
            prices.pop()

        while len(prices)/2>k:
            minL=(0, abs(prices[0]-prices[1]))
            for i in xrange(1, len(prices)-1):
                dL=abs(prices[i]-prices[i+1])
                if dL<minL[1]:
                    minL=(i, dL)
            prices.pop(minL[0])
            prices.pop(minL[0])

        profit=0
        for i in xrange(len(prices)/2):
            profit+=prices[i*2+1]-prices[i*2]

        return profit


if __name__=="__main__":
    s=Solution()
    print s.maxProfit(2, [2, 2, 2, 2, 5, 5, 5])
