struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Não tenho certeza de como esse problema está esperando que eu use menos memória do que isso, mas aqui está o negócio:

// vamos usar 3 variáveis: prevNode, heade nextNode, que você pode facilmente adivinhar o que deve representar à medida que avançamos;
// vamos inicializar prevNodecom NULL, enquanto nextNodepode ficar vazio;
// vamos então fazer um loop até que nosso iterador principal atual ( head) seja verdadeiro (ou seja: não NULL), o que implicaria que chegamos ao final da lista;
// durante a iteração, primeiro atualizamos nextNodepara que adquira seu valor homônimo, o do próximo nó de fato: head->next;
// então procedemos "invertendo" head->nexte atribuindo-lhe o valor de prevNode, enquanto prevNodeque se tornará o valor atual de head;
// finalmente, atualizamos headcom o valor que armazenamos nextNodee continuamos com o loop até que possamos. Após o loop, retornamos prevNode.

// Eu sei que é complexo, mas acho esse gif de outra plataforma para deixar toda a lógica bem mais fácil de entender (lembre-se que não precisamos curre vamos apenas usar headno lugar):
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *aux, *invertido = nullptr; //iinvertido = prevNode
        //aux = nextNode
        while (head)
        {
            aux = head->next;
            head->next = invertido;

            invertido = head;
            head = aux;
        }
        return invertido;
    }
};