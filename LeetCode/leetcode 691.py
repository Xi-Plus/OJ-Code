class Solution:
    def minStickers(self, stickers, target):
        targetdict = {}
        for char in target:
            if char not in targetdict:
                targetdict[char] = 0
            targetdict[char] += 1

        pool = [{'cost': 0}]
        for sticker in stickers:
            for i in range(len(pool)):
                print(pool)
                temp = pool[i].copy()
                for j in range(1, 16):
                    temp['cost'] += 1
                    ok = False
                    for char in sticker:
                        if char not in temp:
                            temp[char] = 0
                        temp[char] += 1
                        if char in targetdict and temp[char] <= targetdict[char]:
                            ok = True
                    if ok:
                        pool.append(temp.copy())
                    else:
                        break
        ans = 1e10
        for pack in pool:
            if pack['cost'] >= ans:
                continue
            ok = True
            for char in targetdict:
                if char not in pack or pack[char] < targetdict[char]:
                    ok = False
                    break
            if ok:
                ans = pack['cost']
        if ans == 1e10:
            return -1
        return ans


if __name__ == "__main__":
    print(Solution().minStickers(["with", "example", "science"], "thehat"))
    print(Solution().minStickers(["notice", "possible"], "basicbasic"))
    # print(Solution().minStickers([
    #     "control", "heart", "interest", "stream", "sentence", "soil", "wonder", "them", "month", "slip", "table", "miss", "boat", "speak", "figure", "no", "perhaps", "twenty", "throw", "rich", "capital", "save", "method", "store", "meant", "life", "oil", "string", "song", "food", "am", "who", "fat", "if", "put", "path", "come", "grow", "box", "great", "word", "object", "stead", "common", "fresh", "the", "operate", "where", "road", "mean"], "stoodcrease"))
