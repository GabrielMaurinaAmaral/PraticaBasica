if __name__ == '__main__':
    num = int(input())
    vetor = map(int, input().split())

vetor = sorted(vetor, reverse=True)

for i in range(len(vetor)):
    if vetor[i] != vetor[0]:
        print(vetor[i])
        break
