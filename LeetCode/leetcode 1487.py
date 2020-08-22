class Solution:
    def getFolderNames(self, names):
        cnt = {}
        used = set()
        answer = []
        for name in names:
            if name not in used:
                used.add(name)
                answer.append(name)
                cnt[name] = 1
            else:
                if name not in cnt:
                    i = 1
                else:
                    i = cnt[name]
                newname = '{}({})'.format(name, i)
                while newname in used:
                    i += 1
                    newname = '{}({})'.format(name, i)
                used.add(newname)
                answer.append(newname)
                cnt[name] = i + 1
        return answer


if __name__ == "__main__":
    print(Solution().getFolderNames(["pes", "fifa", "gta", "pes(2019)"]))
    print(Solution().getFolderNames(["gta", "gta(1)", "gta", "avalon"]))
    print(Solution().getFolderNames(["onepiece", "onepiece(1)", "onepiece(2)", "onepiece(3)", "onepiece"]))
    print(Solution().getFolderNames(["wano", "wano", "wano", "wano"]))
    print(Solution().getFolderNames(["kaido", "kaido(1)", "kaido", "kaido(1)"]))
