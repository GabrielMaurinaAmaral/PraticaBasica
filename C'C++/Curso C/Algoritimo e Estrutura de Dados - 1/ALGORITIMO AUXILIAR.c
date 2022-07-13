typedef struct Cell Cell;

struct Cell
{
    int item;
    Cell *next;
};

typedef struct listaE
{
    Cell *head;
} listaE;

typedef struct hashTA
{
    unsigned int tam;
    listaE *buckets;
} hashTA;

void liberar(hashTA *hTA);

Cell *criar_celula(int num);

hashTA *criar_hashTA(int tam);

void imprimir_hTA(hashTA *hTA, int tam, int *pos);

void inserir_hashTA(hashTA *hTA, int tam, int *pos, int kQuant);

int h1(int k, int B);

int main()
{
    int tam, kQuant;

    scanf("%d", &tam);
    hashTA *hTA = criar_hashTA(tam);

    scanf("%d", &kQuant);
    int pos = (int)malloc(kQuant * sizeof(int));
    
    inserir_hashTA(hTA, tam, pos, kQuant);
    imprimir_hTA(hTA, kQuant, pos);

    liberar(hTA);

    return 0;
}

int h1(int k, int B)
{
    return k % B;
}

Cell *criar_celula(int num)
{
    Cell *novo = malloc(sizeof(Cell));
    novo->item = num;
    novo->next = NULL;

    return novo;
}

hashTA *criar_hashTA(int tam)
{
    hashTA *hTA = malloc(sizeof(hashTA));

    hTA->tam = tam;
    hTA->buckets = malloc(sizeof(listaE) * tam);

    for (int i = 0; i < tam; i++)
    {
        hTA->buckets[i].head = criar_celula(-1);
    }

    return hTA;
}

void inserir_hashTA(hashTA *hTA, int tam, int *pos, int kQuant)
{
    int num, l;
    for (int i = 0; i < kQuant; i++)
    {
        scanf("%d", &num);
        pos[i] = h1(num, hTA->tam);

        if (hTA != NULL)
        {
            l = h1(num, hTA->tam);
            Cell *aux, *novo = criar_celula(num);

            aux = hTA->buckets[l].head;

            while (aux != NULL)
            {
                while (aux->item > 0)
                {
                    if (aux->next == NULL)
                        aux->next = criar_celula(-1);

                    aux = aux->next;
                }

                if (aux->item <= 0)
                    aux->item = novo->item;

                aux = aux->next;
            }
        }
    }
}

void liberar(hashTA *hTA)
{
    if (hTA != NULL)
    {
        free(hTA->buckets);
        free(hTA);
    }
}

void imprimir_hTA(hashTA *hTA, int tam, int *pos)
{
    int i;

    for (i = 0; i < tam; i++)
        printf("%d\n", pos[i]);

    if (hTA != NULL)
    {
        printf("\n");
        Cell *aux;

        for (i = 0; i < hTA->tam; i++)
        {
            aux = hTA->buckets[i].head;
            printf("%d: -> ", i);

            while (aux != NULL)
            {
                if (aux->item > 0)
                    printf("%d ", aux->item);

                if (aux->next != NULL)
                    printf("-> ");

                aux = aux->next;
            }
            printf("\n");
        }
    }
}