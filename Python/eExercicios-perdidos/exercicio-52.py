i = int(input("Enter a number: "))
aux = 0

for a in range(1, i+1):
    if 1 % a == 0 or i % a == 0:
        aux += 1
        print(a)

if aux == 2:
    print("{} is prime number".format(i))
else:
    print("{} it's not prime number".format(i))
