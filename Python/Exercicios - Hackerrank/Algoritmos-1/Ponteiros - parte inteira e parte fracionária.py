from random import randrange


def jogar():
    imprime_mensagem_abertura()
    palavra_secreta = carrega_palavra_secreta()

    # Modo de usar o for em apenas uma linha, LIST COMPREHENSIONS!!
    letras_acertadas = ['_' for letra in palavra_secreta]
    print(letras_acertadas)

    enforcou = False
    acertou = False
    erros = 0

    while(not enforcou and not acertou):
        chute = pede_chute()
        print(chute)

        if(chute in palavra_secreta):
            marca_chute_correto(chute, letras_acertadas, palavra_secreta)
        else:
            erros += 1
            desenha_forca(erros)

        enforcou = erros == 7
        acertou = "_" not in letras_acertadas
        print(letras_acertadas)

    if(acertou):
        imprime_mensagem_vencedor()
    else:
        imprime_mensagem_perdedor(palavra_secreta)


def imprime_mensagem_abertura():
    print('*********************************')
    print('***Bem vindo ao jogo da Forca!***')
    print('*********************************')


def carrega_palavra_secreta():

    palavras = []
    # with é usado para abrir arquivos e deixar o python
    with open("palavras.txt", "r", encoding="UTF-8") as arquivo:
        for linha in arquivo:  # responsavel por fecha-lo automaticamente caso dê erro no programa
            linha = linha.strip()  # Pesquisar mais sobre with e a função open()
            palavras.append(linha)

    print(palavras)

    palavra_secreta = palavras[randrange(len(palavras))].upper()
    arquivo.close()
    return palavra_secreta


def pede_chute():
    chute = input('Qual letra? ').upper().strip()
    return chute


def marca_chute_correto(chute, letras_acertadas, palavra_secreta):
    index = 0
    for letra in palavra_secreta:
        if chute == letra:
            letras_acertadas[index] = letra
        index += 1


def imprime_mensagem_vencedor():
    #OMITIDO
    pass


def imprime_mensagem_perdedor(palavra_secreta):
    #OMITIDO
    pass


def desenha_forca(erros):
    #OMITIDO
    pass

jogar()