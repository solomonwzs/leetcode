#!/usr/bin/python3
# -*- coding: utf-8 -*-
#
# @author   Solomon Ng <solomon.wzs@gmail.com>
# @date     2019-04-27
# @version  1.0
# @license  MIT


def findK(nums1: list, nums2: list, k: int) -> int:
    len1 = len(nums1)
    len2 = len(nums2)
    if len1 == 0:
        return nums2[k]
    elif len2 == 0:
        return nums1[k]
    elif k == 0:
        return min(nums1[0], nums2[0])
    elif k == 1:
        if nums1[0] > nums2[0]:
            return findK(nums1, nums2[1:], 0)
        else:
            return findK(nums1[1:], nums2, 0)
    elif len1 == 1:
        return findK(nums1, nums2[k - 1:], 1)
    elif len2 == 1:
        return findK(nums1[k - 1:], nums2, 1)

    mid1 = len1 // 2
    mid2 = len2 // 2
    if mid1 + mid2 >= k:
        if nums1[mid1] > nums2[mid2]:
            return findK(nums1[:mid1], nums2, k)
        else:
            return findK(nums1, nums2[:mid2], k)
    else:
        if nums1[mid1] > nums2[mid2]:
            return findK(nums1, nums2[mid2:], k - mid2)
        else:
            return findK(nums1[mid1:], nums2, k - mid1)


class Solution:
    def findMedianSortedArrays(self, nums1: list, nums2: list) -> float:
        l1 = len(nums1)
        l2 = len(nums2)
        if (l1 + l2) % 2 == 1:
            return float(findK(nums1, nums2, (l1 + l2) // 2))
        else:
            k1 = findK(nums1, nums2, (l1 + l2) // 2)
            k2 = findK(nums1, nums2, (l1 + l2) // 2 - 1)
            return float((k1 + k2) / 2)


if __name__ == "__main__":
    s = Solution()
    print(">>", s.findMedianSortedArrays([1, 2], [3, 4]) == 2.5)
    print(">>", s.findMedianSortedArrays([1, 3], [2]) == 2.0)
    print(">>", s.findMedianSortedArrays([1, 2], [1, 2, 3]) == 2.0)
    print(">>", s.findMedianSortedArrays([1], [2, 3, 4]) == 2.5)
    print(">>", s.findMedianSortedArrays([3], [1, 2, 4]) == 2.5)
    print(">>", s.findMedianSortedArrays([3], [1, 2, 4]) == 2.5)
    print(">>", s.findMedianSortedArrays([1, 2], [-1, 3]) == 1.5)
