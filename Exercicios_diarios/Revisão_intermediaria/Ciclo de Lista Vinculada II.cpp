struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *lento = head, *rapido = head;
        while (rapido && rapido->next)
        {
            lento = lento->next;
            rapido = rapido->next->next;
            if (lento == rapido)
                break;
        }
        if (!(rapido && rapido->next))
            return nullptr;
        while (head != lento)
        {
            head = head->next;
            lento = lento->next;
        }
        return head;
    }
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *lento = head, *rapido = head;

        while (rapido != nullptr && rapido->next != nullptr)
        {
            lento = lento->next;
            rapido = rapido->next->next;
            if (lento == rapido)
            {
                while (head != rapido)
                {
                    head = head->next;
                    rapido = rapido->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};
