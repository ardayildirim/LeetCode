# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    # I couldn't solve this problem with C++ unfortunately.
    # Because of long int overflows.
    def addTwoNumbers(self, l1, l2):
        first = 0
        second = 0
        while l1:
            first = first  * 10 + l1.val
            l1 = l1.next
        while l2:
            second = second  * 10 + l2.val
            l2 = l2.next
        res = first + second
        digits = []
        if res == 0:
            ans = ListNode(0,None)
            return ans
        while res > 0:
            digits.append(res%10)
            res = int(res / 10)
        ans = ListNode(0,None)
        t = ans
        for i in reversed(digits):
            t.next = ListNode(i,None)
            t = t.next
        return ans.next
