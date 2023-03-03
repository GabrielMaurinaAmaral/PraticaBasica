class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1, list2):
        if not list1 or not list2:
            return list1 or list2

        if list1.val < list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2


class Solution:
    def mergeTwoLists(self, list1, list2):
        list3 = aux = ListNode(0)

        while list1 and list2:
            if list1.val < list2.val:
                aux.next = list1
                list1 = list1.next
            else:
                aux.next = list2
                list2 = list2.next
                
            aux = aux.next

        aux.next = list1 or list2

        return list3.next
