vetor = []

for i in range(0, 5):
    n = int(input("digite um valor"))

    if i == 0 or n>vetor[-1]:
        vetor.append(n)
        print("add final")
    else:
        pos = 0
        while pos < len(vetor):
            if n <= vetor[pos]:
                l = vetor.insert(pos, n)
                print("add ", pos)
                break
            pos += 1

print('='*20)
print(vetor)
