
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int cont = 0;
        ListNode *aux = head;
        while (head)
        {
            head = head->next;
            cont += 1;
        }
        for (int i = 0; i < cont / 2; i++)
            aux = aux->next;
        return aux;
    }
};