##
##
##

pessoa=dict()
lista=list()
soma=0

while True:
    pessoa['nome']=str(input("NOME: "))
    pessoa['sexo']=str(input("SEXO: "))
    pessoa['idade']=int(input("IDADE: "))
    soma+=pessoa['idade']
    lista.append(pessoa.copy())
    pessoa.clear
    
    opc=str(input('continue: '))
    if opc in 'Nn':
        break

print("soma: {}".format(soma))
print("media: ".format(soma/len(lista)))