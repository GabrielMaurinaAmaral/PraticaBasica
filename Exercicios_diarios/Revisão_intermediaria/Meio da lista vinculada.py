class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cont = 0
        aux = head
        while head:
            head = head.next
            cont += 1
        for i in range(int(cont / 2)):
            aux = aux.next
            i+=1
        return aux
