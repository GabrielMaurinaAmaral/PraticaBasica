char repete(char rep)
{
    do
        {
            printf("Deseja repetir?\n");
            setbuf(stdin, NULL);
            scanf("%c", &rep);
            if(rep!= 'S' && rep!='N' && rep!= 's' && rep!='n')
            {
                printf("Caractere Invalido\n");
            }
        }while(rep!= 'S' && rep!='N' && rep!= 's' && rep!='n');
        return(rep);
}
