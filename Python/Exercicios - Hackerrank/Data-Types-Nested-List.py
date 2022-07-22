matriz = []
score_list = []

for i in range(int(input())):
    name = str(input())
    score = float(input())
    matriz.append([name, score])
    score_list.append(score)

menor = sorted(set(score_list))[1]

for name, score in sorted(matriz):
    if score == menor:
        print(name)
