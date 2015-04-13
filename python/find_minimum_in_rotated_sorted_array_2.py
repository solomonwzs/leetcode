class Solution:
    def findMin(self, num):
        head=0
        last=len(num)-1

        while head<last-1:
            mid=(head+last)/2
            if num[head]<num[mid] and num[mid]<num[last]:
                return num[head]
            elif num[head]<num[mid] and num[mid]>num[last]:
                if (num[head]<num[last]):
                    last=mid
                else:
                    head=mid
            else:
                last=mid

        if head==last:
            return num[head]
        else:
            return num[head] if num[head]<num[last] else num[last]


if __name__=="__main__":
    s=Solution()
    print s.findMin([4, 5, 6, 7, 0, 1, 2])
