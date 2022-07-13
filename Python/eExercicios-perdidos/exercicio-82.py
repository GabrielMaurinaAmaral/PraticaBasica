vector = []
par = []
impar = []
while True:
    vector.append(int(input("Enter a number: ")))
    opc = str(input("continue: "))

    if opc in "Nn":
        break

for i, v in enumerate(vector):
    if v % 2 == 0:
        par.append(v)
    elif v % 2 != 0:
        impar.append(v)

print(vector)
print(par)
print(impar)
