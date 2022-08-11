# print zip([1, 2, 3, 4, 5, 6], 'Hacker')
# [(1, 'H'), (2, 'a'), (3, 'c'), (4, 'k'), (5, 'e'), (6, 'r')]
#
# print zip([1, 2, 3, 4, 5, 6], [0, 9, 8, 7, 6, 5, 4, 3, 2, 1])
# [(1, 0), (2, 9), (3, 8), (4, 7), (5, 6), (6, 5)]
#
# A = [1, 2, 3]
# B = [6, 5, 4]
# C = [7, 8, 9]
# X = [A] + [B] + [C]
#
# print zip(*X)
# [(1, 6, 7), (2, 5, 8), (3, 4, 9)]

len_1, len_2 = map(int, input().split())
notas = list()

for _ in range(len_2):
    notas.append(list(map(float, input().split())))

for nota in list(zip(*notas)):
    print(sum(nota) / len(nota))
