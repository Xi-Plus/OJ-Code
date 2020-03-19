# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseKGroup(self, head, k):
        if k < 2:
            return head
        newhead = head
        for i in range(k - 1):
            newhead = newhead.next
        for i in range(k - 1):
            nexthead = head.next
            head.next = newhead.next
            newhead.next = head
            head = nexthead
        return newhead


if __name__ == "__main__":
    for k in [2, 3]:
        temp = ListNode(1)
        temp.next = ListNode(2)
        temp.next.next = ListNode(3)
        temp.next.next.next = ListNode(4)
        temp.next.next.next.next = ListNode(5)
        ans = Solution().reverseKGroup(temp, k)
        values = []
        while ans is not None:
            values.append(ans.val)
            ans = ans.next
        print(values)
