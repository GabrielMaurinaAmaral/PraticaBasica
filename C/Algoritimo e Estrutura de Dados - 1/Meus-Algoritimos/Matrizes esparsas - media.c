float *media_col(MatE *mat)
{
    float *vet = NULL;
    int i;
    Cell *aux;

    if (mat != NULL)
    {
        vet = calloc(mat->col, sizeof(int));

        for (i = 0; i < mat->lin; i++)
        {
            aux = mat->mat[i]->head;

            while (aux != NULL)
            {
                vet[aux->col] += aux->item;
                aux = aux->next;
            }
        }

        for (i = 0; i < mat->col; i++)
            vet[i] /= mat->lin;
    }

    return vet;
}