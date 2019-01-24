# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        root = ListNode(-1)
        now = root
        while l1 is not None and l2 is not None:
            if l1.val <= l2.val:
                now.next = ListNode(l1.val)
                l1 = l1.next
                now = now.next
            else:
                now.next = ListNode(l2.val)
                l2 = l2.next
                now = now.next
        while l1 is not None:
            now.next = ListNode(l1.val)
            l1 = l1.next
            now = now.next
        while l2 is not None:
            now.next = ListNode(l2.val)
            l2 = l2.next
            now = now.next
        return root.next
