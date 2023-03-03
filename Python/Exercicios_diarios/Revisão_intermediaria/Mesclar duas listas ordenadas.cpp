#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;

        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }

        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *list3;
        if (list1->val <= list2->val)
        {
            list3 = list1;
            list1 = list1->next;
        }
        else
        {
            list3 = list2;
            list2 = list2->next;
        }

        ListNode *aux = list3;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                aux->next = list1;
                list1 = list1->next;
            }
            else
            {
                aux->next = list2;
                list2 = list2->next;
            }
            aux = aux->next;
        }

        if (!list1) 
            aux->next = list2;
        else
            aux->next = list1;

        return list3;
    }
};