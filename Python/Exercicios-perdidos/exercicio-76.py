lista = ("lista", 1.75, "borracha", 2, "caderno", 15.9, "estojo", 25, "tranferidor",
         4.2, "compasso", 9.99, "mochila", 120.32, "caderno", 22.3, "livro", 34.9)
print("Lista de preço")

for pos in range(0, len(lista)):
    print("="*20)
    if pos % 2 == 0:
        print(lista[pos], end='')
    else:
        print(lista[pos])
