import re

texto = "gabriel maurina amral é um gostoso uiiiiiii"
pesquisa = str(input("pesquisar: "))
resposta = re.sub(" ", pesquisa, texto)  # SUBSTITUI CARACTERES

print(resposta)
