class Solution:
    def isAlienSorted(self, words, order):
        for i in range(len(words)):
            words[i] += '@'
        order = '@' + order
        self.ans = True
        self._check(words, order, 0, len(words) - 1, 0)
        return self.ans

    def _check(self, words, order, i, j, k):
        if i == j:
            return
        prediff = 0
        for a in range(i, j):
            if words[a][k] != words[a + 1][k]:
                print(a, k, words[a][k], words[a + 1][k])
                if order.index(words[a][k]) > order.index(words[a + 1][k]):
                    self.ans = False
                self._check(words, order, prediff, a, k + 1)
                prediff = a + 1

        self._check(words, order, prediff, j, k + 1)
