import re

texto = "gabriel maurina amral é um gostoso uiiiiiii"

pesquisa = str(input("pesquisar: "))
resposta = re.search(pesquisa, texto)

if(resposta != None):
    parte_inicial = resposta.start()
    parte_final = resposta.end()
    tamanho = parte_final-parte_inicial
    print(parte_inicial)
    print(parte_final)
    print(tamanho)
    print(resposta)

else:
    print("nao encontrado")
