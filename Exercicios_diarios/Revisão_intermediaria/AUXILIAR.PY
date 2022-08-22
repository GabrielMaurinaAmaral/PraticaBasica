def solution(sequence):
    result = False
    antes = depois = min(sequence) - 1
    for num in sequence:
        if num <= antes:
            if result:
                return False
            else:
                result = True
            if num <= depois:
                depois = antes
            elif num >= depois:
                depois = antes = num
        else:
            depois, antes = antes, num
    return True


def matrixElementsSum(matriz):
    len_coluna = len(matriz)
    len_linha = len(matriz[0])
    soma = 0
    for j in range(len_coluna):
        for i in range(len_linha):
            if matriz[i][j] != 0:
                soma += matriz[i][j]
            else:
                break
    return soma


def All_Longest_Strings(inputArray):
    maior = 0
    result = []
    for s in inputArray:
        if maior < len(s):
            maior = len(s)
        if len(s) == maior:
            result.append(s)
    return result
