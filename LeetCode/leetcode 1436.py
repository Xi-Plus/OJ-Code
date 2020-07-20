class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        return list(set([v[1] for v in paths]) - set([v[0] for v in paths]))[0]
