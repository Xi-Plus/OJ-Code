# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeKLists(self, lists):
        anshead = None
        ansnow = None
        while True:
            minv = 1e10
            mink = -1
            for i in range(len(lists)):
                if lists[i] is not None and lists[i].val < minv:
                    mink = i
                    minv = lists[i].val
            if mink == -1:
                break
            if anshead is None:
                anshead = ListNode(minv)
                ansnow = anshead
            else:
                ansnow.next = ListNode(minv)
                ansnow = ansnow.next
            lists[mink] = lists[mink].next
        return anshead


if __name__ == "__main__":
    temp = []
    temp.append(ListNode(1))
    temp[0].next = ListNode(4)
    temp[0].next.next = ListNode(5)
    temp.append(ListNode(1))
    temp[1].next = ListNode(3)
    temp[1].next.next = ListNode(4)
    temp.append(ListNode(2))
    temp[2].next = ListNode(6)

    ans = Solution().mergeKLists(temp)
    values = []
    while ans is not None:
        values.append(ans.val)
        ans = ans.next
    print(values)
