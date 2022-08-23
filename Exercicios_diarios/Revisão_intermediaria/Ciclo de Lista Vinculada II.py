class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def detectCycle(self, head):
        lento = rapido = head
        while rapido and rapido.next:
            lento, rapido = lento.next, rapido.next.next
            if lento == rapido:
                break
        else:
            return None
        while head != lento:
            head, lento = head.next, lento.next
        return head


class Solution:
    def detectCycle(self, head):
        lento, rapido = head, head
        while rapido and rapido.next:
            lento = lento.next
            rapido = rapido.next.next
            if lento == rapido:
                while head != rapido:
                    head = head.next
                    rapido = rapido.next
                return head
        return None