# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def swapNodes(self, head, k):
        l = r = head
        for i in range(k - 1):
            l = l.next
        temp = l
        while temp.next:
            r = r.next
            temp = temp.next
        l.val, r.val = r.val, l.val
        return head
