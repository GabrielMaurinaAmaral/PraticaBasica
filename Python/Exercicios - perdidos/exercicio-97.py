def texto(nome):
    tam=len(nome)
    print('='*tam)
    print(f'{nome}')
    print('='*tam)


t=str(input("escreva um texto: "))
texto(t)
