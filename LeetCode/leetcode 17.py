import itertools

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == '':
            return []
        letters = ',,abc,def,ghi,jkl,mno,pqrs,tuv,wxyz'.split(',')
        arr = [list(letters[int(n)]) for n in digits]
        return [''.join(s) for s in itertools.product(*arr)]
