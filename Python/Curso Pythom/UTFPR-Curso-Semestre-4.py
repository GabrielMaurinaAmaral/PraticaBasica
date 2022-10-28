def tangente(cateto_oposto: float, cateto_adjacente: float) -> float:
    tangente = cateto_oposto / cateto_adjacente
    return tangente


def somar(a, b):
  resultado = a+b
  return resultado


def cont_char(palavra: str, texto: str) -> int: #dicas de tipo
    lista_palavras = texto.split(" ")
    print(lista_palavras)
    cont = 0

    for s in lista_palavras:
        if palavra in s:
            cont += 1
    print(cont)


soma = somar(10, 5)
print(soma)
soma = somar(1.43, 523.43)
print(soma)
texto = "Gabreiel Maurina Amaral"
letra = str(input())
cont_char(letra, texto)

pot=[2**i for i in range(10)]