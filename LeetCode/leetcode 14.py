class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        minlen = len(strs[0])
        for s in strs:
            minlen = min(minlen, len(s))
        ans = 0
        i = 0
        while i < minlen:
            for j in range(len(strs) - 1):
                if strs[j][i] != strs[j+1][i]:
                    return strs[0][:ans]
            i += 1
            ans += 1
        return strs[0][:ans]
