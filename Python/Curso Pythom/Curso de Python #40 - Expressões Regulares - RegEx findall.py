from cgitb import text
import re

texto = "gabriel maurina amaral e um gostoso"

# pesquisa e retorna uma colesao que repetiu tal parte
resultado = re.findall("amaral", texto)
print(resultado)

pesquisa = input("Pesquisar: ")
resultado1 = re.findall(pesquisa, texto)
print(resultado1)

quantidade_pesquisa = len(resultado1)
print(f"quantiodade: {quantidade_pesquisa}")

for r in resultado1:
    print(r)

#compreenção de lista
potencia = [2**i for i in range(10)]
print(potencia)