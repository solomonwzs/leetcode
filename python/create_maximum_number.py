class Solution(object):
    def __maxNumberOneLine(self, nums, k):
        select = [0] * len(nums)
        p = len(nums) - k

        for i in xrange(p, len(nums)):
            select[i] = 1

        for i in xrange(p - 1, -1, -1):
            pass

    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        l1 = []
        for i, num in enumerate(nums1):
            l1.append(Node(num, i))
        l1.sort()

        l2 = []
        for i, num in enumerate(nums2):
            l2.append(Node(num, i))
        l2.sort()


if __name__ == "__main__":
    s = Solution()
    s.maxNumber([3, 4, 6, 5], [9, 1, 2, 5, 8, 3], 5)
