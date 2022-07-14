num = [2, 5, 9, 1]
print(num)
num[2] = 3
num.append(7)
num.sort(reverse=True)
num.insert(2, 0)
if 5 in num:
    num.remove(5)
print(num)
print("Lista tem {} elementos".format(len(num)))
print("="*20)

valor = []
valor.append(1)
valor.append(2)
valor.append(3)
valor.append(4)
valor.append(5)
for v in valor:
    print("{}...".format(v), end='')
print("="*20)

a = [1, 2, 3]
b = [9, 8, 7]
print("lista a: ", a)
print("lista b: ", b)
