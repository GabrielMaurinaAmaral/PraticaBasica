vetor = []
menor = 0
maior = 0

for i in range(0, 5):
    vetor.append(int(input("enter a number: ")))

    if i == 0:
        maior = menor = vetor[i]

    else:
        if vetor[i] > maior:
            maior = vetor[i]
        if vetor[i] < menor:
            menor = vetor[i]

print(vetor)
print("menor: ", menor)
print("maior: ", maior)
