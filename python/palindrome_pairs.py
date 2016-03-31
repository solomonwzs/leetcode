class Solution(object):
    def isPalindrome(self, word):
        l = len(word)
        for i in xrange(l / 2):
            if word[i] != word[- (i + 1)]:
                return False
        return True

    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        d = {}
        for i, word in enumerate(words):
            d[word] = i

        res = []
        for i, word in enumerate(words):
            for j in xrange(len(word) + 1):
                left = word[0:j]
                right = word[j:]

                if self.isPalindrome(right):
                    ridx = d.get(left[::-1])
                    if ridx is not None and ridx != i:
                        if not(right == "" and i < ridx):
                            res.append([i, ridx])

                if self.isPalindrome(left):
                    lidx = d.get(right[::-1])
                    if lidx is not None and lidx != i:
                        if not(left == "" and i < lidx):
                            res.append([lidx, i])
        return res


if __name__ == "__main__":
    s = Solution()
    print s.palindromePairs(["a", ""])
    print s.palindromePairs(["abcd", "dcba", "lls", "s", "sssll"])
