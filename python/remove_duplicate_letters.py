class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = [0] * 26
        exist = [False] * 26
        for ch in s:
            cnt[ord(ch) - ord('a')] += 1

        res = []
        for ch in s:
            idx = ord(ch) - ord('a')
            cnt[idx] -= 1

            if len(res) == 0:
                res.append(ch)
                exist[idx] = True
            elif res[-1] < ch and not exist[idx]:
                if exist[idx]:
                    continue
                else:
                    res.append(ch)
                    exist[idx] = True
            elif res[-1] > ch and not exist[idx]:
                while cnt[ord(res[-1]) - ord('a')] > 0 and res[-1] > ch:
                    exist[ord(res[-1]) - ord('a')] = False
                    res.pop()
                    if len(res) == 0:
                        break
                res.append(ch)
                exist[idx] = True

        return ''.join(res)


if __name__ == "__main__":
    s = Solution()
    print s.removeDuplicateLetters("cbacdcbc")
