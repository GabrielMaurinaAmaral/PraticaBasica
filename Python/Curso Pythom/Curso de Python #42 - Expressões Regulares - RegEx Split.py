import re

texto = "gabriel maurina amral é um gostoso uiiiiiii"
pesquisa = str(input("pesquisar: "))
resposta = re.split(pesquisa, texto)

print(resposta)

for t in resposta:
    print(t)
