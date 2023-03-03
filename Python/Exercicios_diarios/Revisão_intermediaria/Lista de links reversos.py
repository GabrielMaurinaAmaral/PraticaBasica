class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head):
        invertido = None
        
        while head:
            aux = head
            head = head.next
            
            aux.next = invertido
            invertido = aux
        return invertido