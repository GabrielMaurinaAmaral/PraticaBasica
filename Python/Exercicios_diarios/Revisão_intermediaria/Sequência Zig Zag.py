def findZigZagSequence(vetor, len):
    vetor.sort()
    meio = int((len - 1)/2)
    vetor[meio], vetor[len-1] = vetor[len-1], vetor[meio]

    esquerda = meio + 1
    direita = len - 2
    while(esquerda <= direita):
        vetor[esquerda], vetor[direita] = vetor[direita], vetor[esquerda]
        esquerda = esquerda + 1
        direita = direita - 1

    for i in range(len):
        if i == len-1:
            print(vetor[i])
        else:
            print(vetor[i], end=' ')
    return 0


test_cases = int(input())
for cs in range(test_cases):
    len = int(input())
    vetor = list(map(int, input().split()))
    findZigZagSequence(vetor, len)
